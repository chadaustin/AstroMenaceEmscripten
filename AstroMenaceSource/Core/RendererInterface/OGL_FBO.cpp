/************************************************************************************

	AstroMenace (Hardcore 3D space shooter with spaceship upgrade possibilities)
	Copyright © 2006-2013 Michael Kurinnoy, Viewizard


	AstroMenace is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	AstroMenace is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with AstroMenace. If not, see <http://www.gnu.org/licenses/>.


	Web Site: http://www.viewizard.com/
	Project: http://sourceforge.net/projects/openastromenace/
	E-mail: viewizard@viewizard.com

*************************************************************************************/


#include "RendererInterface.h"
extern eDevCaps OpenGL_DevCaps;

// текущий работающий буфер, если 0 - фрейм буфер
eFBO *CurrentFBO = 0;


//------------------------------------------------------------------------------------
// Инициализация работы с FBO
//------------------------------------------------------------------------------------
bool vw_Internal_InitializationFBO()
{
	return true;
}








//------------------------------------------------------------------------------------
// Создаем FBO с заданными параметрами (FBO - уже заранее подготовленный объект, в функции память не выделяем)
//------------------------------------------------------------------------------------
bool vw_BuildFBO(eFBO *FBO, int Width, int Height, bool NeedColor, bool NeedDepth, int MSAA, int *CSAA)
{
	if (FBO == 0) return false;

	// если не поддерживаем ковередж - просто ставим MSAA
        if (CSAA != 0)
            *CSAA = MSAA;

	int InternalCSAA = MSAA;
	if (CSAA != 0) InternalCSAA = *CSAA;


	FBO->Width = Width;
	FBO->Height = Height;
	FBO->ColorBuffer = 0;
	FBO->DepthBuffer = 0;
	FBO->ColorTexture = 0;
	FBO->DepthTexture = 0;
	FBO->FrameBufferObject = 0;
	FBO->DepthSize = 0;

	printf("Frame Buffer Object creation start with parameters %i %i %i %i %i %i\n", Width, Height, NeedColor, NeedDepth, MSAA, InternalCSAA);

	glGenFramebuffers(1, &FBO->FrameBufferObject);
	glBindFramebuffer(GL_FRAMEBUFFER, FBO->FrameBufferObject);


	if (NeedColor)
	{
		// если есть мультисемплы - делаем буфером, если нет - текстурой
		if (MSAA >= 2)
		{
			glGenRenderbuffers(1, &FBO->ColorBuffer);
			glBindRenderbuffer(GL_RENDERBUFFER, FBO->ColorBuffer);
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, FBO->ColorBuffer);
			if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			{
				fprintf(stderr, "Can't create FRAMEBUFFER.\n\n");
				return false;
			}
		}
		else
		{
			glGenTextures(1, &FBO->ColorTexture);
			glBindTexture(GL_TEXTURE_2D, FBO->ColorTexture);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, FBO->Width, FBO->Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, FBO->ColorTexture, 0);
			if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			{
				fprintf(stderr, "Can't create FRAMEBUFFER.\n\n");
				return false;
			}
		}
	}


	if (NeedDepth)
	{
		// если есть мультисемплы - делаем буфером, если нет - текстурой
		if (MSAA >= 2)
		{
			glGenRenderbuffers(1, &FBO->DepthBuffer);
			glBindRenderbuffer(GL_RENDERBUFFER, FBO->DepthBuffer);
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, FBO->DepthBuffer);
			// получаем назначенную драйвером глубину depth буфера
			glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE, &FBO->DepthSize);
			if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			{
				fprintf(stderr, "Can't create FRAMEBUFFER.\n\n");
				return false;
			}
		}
		else
		{
			glGenTextures(1, &FBO->DepthTexture);
			glBindTexture(GL_TEXTURE_2D, FBO->DepthTexture);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			// Ставим "GL_DEPTH_COMPONENT" (No need to force GL_DEPTH_COMPONENT24, drivers usually give you the max precision if available ...)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, FBO->Width, FBO->Height, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, 0);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, FBO->DepthTexture, 0);
			// получаем назначенную драйвером глубину depth буфера
			glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE, &FBO->DepthSize);
			if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			{
				fprintf(stderr, "Can't create FRAMEBUFFER.\n\n");
				return false;
			}
		}
	}


	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	printf("Frame Buffer Object created. Depth Size: %i\n", FBO->DepthSize);

	// запоминаем максимальные полученные данные по буферу глубины
	if (OpenGL_DevCaps.FramebufferObjectDepthSize < FBO->DepthSize) OpenGL_DevCaps.FramebufferObjectDepthSize = FBO->DepthSize;

	return true;
}







//------------------------------------------------------------------------------------
// Установка FBO
//------------------------------------------------------------------------------------
void vw_BindFBO(eFBO *FBO)
{
	if (FBO != 0)
		if (FBO->FrameBufferObject == 0) return;

	// проверяем текущий
	if (CurrentFBO != 0)// если текущий был с мультисемплами - надо их выключить
		if ((CurrentFBO->ColorBuffer != 0) || (CurrentFBO->DepthBuffer != 0)) glDisable(GL_MULTISAMPLE);

	if (FBO != 0)
	{
		if ((FBO->ColorBuffer != 0) || (FBO->DepthBuffer != 0)) glEnable(GL_MULTISAMPLE);
		glBindFramebuffer(GL_FRAMEBUFFER, FBO->FrameBufferObject);
	}
	else
	{
		// ставим основной фрейм буфер
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	CurrentFBO = FBO;
}







//------------------------------------------------------------------------------------
// получаем текущий установленный FBO, 0 - если фрейм буфер
//------------------------------------------------------------------------------------
eFBO *vw_GetCurrentFBO()
{
	return CurrentFBO;
}








//------------------------------------------------------------------------------------
// Блит FBO
//------------------------------------------------------------------------------------
void vw_BlitFBO(eFBO *SourceFBO, eFBO *TargetFBO)
{
    return;
    /*
	if (SourceFBO == 0) return;
	if (SourceFBO->FrameBufferObject == 0) return;
	if (TargetFBO == 0) return;
	if (TargetFBO->FrameBufferObject == 0) return;

	glBindFramebuffer(GL_READ_FRAMEBUFFER, SourceFBO->FrameBufferObject);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, TargetFBO->FrameBufferObject);
	glBlitFramebuffer(
		0, 0, SourceFBO->Width, SourceFBO->Height,
		0, 0, TargetFBO->Width, TargetFBO->Height,
		GL_COLOR_BUFFER_BIT, GL_LINEAR);
    */
}










//------------------------------------------------------------------------------------
// Рисуем FBO в указанный FBO
//------------------------------------------------------------------------------------
void vw_DrawColorFBO(eFBO *SourceFBO, eFBO *TargetFBO)
{
	if (SourceFBO == 0) return;
	if (SourceFBO->ColorTexture == 0) return;


	vw_BindFBO(TargetFBO);
	glViewport(0, 0, SourceFBO->Width, SourceFBO->Height);


	// рисуем текстуру на весь экран

    // запоминаем состояние флагов
	glPushAttrib(GL_ENABLE_BIT);
    // и выключаем "ненужные"
	glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);								//select the projection matrix
	glPushMatrix();												//store the projection matrix
	glLoadIdentity();											//reset the projection matrix

	glOrtho(0, SourceFBO->Width, 0, SourceFBO->Height, -1, 1);

	glMatrixMode(GL_MODELVIEW);				//select the modelview matrix
	glPushMatrix();
	glLoadIdentity();


		float *buff = 0;
		// RI_2f_XY | RI_1_TEX
		buff = new float[4*4]; if (buff == 0) return;

		int k=0;

		buff[k++] = 0.0f;
		buff[k++] = 0.0f;
		buff[k++] = 0.0f;
		buff[k++] = 0.0f;

		buff[k++] = 0.0f;
		buff[k++] = SourceFBO->Height;
		buff[k++] = 0.0f;
		buff[k++] = 1.0f;

		buff[k++] = SourceFBO->Width;
		buff[k++] = 0.0f;
		buff[k++] = 1.0f;
		buff[k++] = 0.0f;

		buff[k++] = SourceFBO->Width;
		buff[k++] = SourceFBO->Height;
		buff[k++] = 1.0f;
		buff[k++] = 1.0f;


		vw_BindTexture(0, SourceFBO->ColorTexture);

		vw_SendVertices(RI_TRIANGLE_STRIP, 4, RI_2f_XY | RI_1_TEX, buff, 4*sizeof(float));

		vw_BindTexture(0, 0);
		if (buff != 0){delete [] buff; buff = 0;}


	glMatrixMode(GL_MODELVIEW);				//select the modelview matrix
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);			//select the projection matrix
	glPopMatrix();							//restore the old projection matrix

	glMatrixMode(GL_MODELVIEW);				//select the modelview matrix

    // восстанавливаем флаги
	glPopAttrib();

}











//------------------------------------------------------------------------------------
// Удаление данных FBO
//------------------------------------------------------------------------------------
void vw_DeleteFBO(eFBO *FBO)
{
	if (FBO == 0) return;

	if (FBO->ColorTexture != 0) {glDeleteTextures(1, &FBO->ColorTexture); FBO->ColorTexture=0;};
	if (FBO->DepthTexture != 0) {glDeleteTextures(1, &FBO->DepthTexture); FBO->DepthTexture=0;};

	if (FBO->ColorBuffer != 0) {glDeleteRenderbuffers(1, &FBO->ColorBuffer); FBO->ColorBuffer=0;};
	if (FBO->DepthBuffer != 0) {glDeleteRenderbuffers(1, &FBO->DepthBuffer); FBO->DepthBuffer=0;};

	if (FBO->FrameBufferObject != 0) {glDeleteFramebuffers(1, &FBO->FrameBufferObject); FBO->FrameBufferObject=0;};
}

