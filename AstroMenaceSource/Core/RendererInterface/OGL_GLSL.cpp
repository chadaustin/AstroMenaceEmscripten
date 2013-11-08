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



// для менеджера
eGLSL *StartGLSLMan = 0;
eGLSL *EndGLSLMan = 0;
int NumGLSLMan = 0;

//------------------------------------------------------------------------------------
// иним и подключаем все указатели
//------------------------------------------------------------------------------------
bool vw_Internal_InitializationGLSL()
{
	// инициализация менеджера
	StartGLSLMan = 0;
	EndGLSLMan = 0;
	NumGLSLMan = 0;

	return true;
}





//------------------------------------------------------------------------------------
// ошибка
//------------------------------------------------------------------------------------
int CheckOGLError()
{
    // Returns 1 if an OpenGL error occurred, 0 otherwise.
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    while (glErr != GL_NO_ERROR)
    {
        fprintf(stderr, "glError 0x%x %s\n", glErr, gluErrorString(glErr));
        retCode = 1;
        glErr = glGetError();
    }
    return retCode;
}


//------------------------------------------------------------------------------------
// Print out the information log for a shader object
//------------------------------------------------------------------------------------
void vw_PrintShaderInfoLog(GLuint shader, const char *ShaderName)
{
    int infologLength = 0;
    int charsWritten  = 0;
    GLchar *infoLog;

    CheckOGLError();  // Check for OpenGL errors

    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infologLength);

    CheckOGLError();  // Check for OpenGL errors

    if (infologLength > 0)
    {
        infoLog = (GLchar *)malloc(infologLength);
        if (infoLog == NULL)
        {
            fprintf(stderr, "ERROR: Could not allocate InfoLog buffer\n");
            return;
        }
        glGetShaderInfoLog(shader, infologLength, &charsWritten, infoLog);
        if (strlen(infoLog) >1)
			printf("Shader InfoLog %s:\n%s\n\n", ShaderName, infoLog);
        free(infoLog);
    }
    CheckOGLError();  // Check for OpenGL errors
}


void vw_PrintProgramInfoLog(GLuint program)
{
    int infologLength = 0;
    int charsWritten  = 0;
    GLchar *infoLog;

    CheckOGLError();  // Check for OpenGL errors

    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infologLength);

    CheckOGLError();  // Check for OpenGL errors

    if (infologLength > 0)
    {
        infoLog = (GLchar *)malloc(infologLength);
        if (infoLog == NULL)
        {
            printf("ERROR: Could not allocate InfoLog buffer\n");
            exit(1);
        }
        glGetProgramInfoLog(program, infologLength, &charsWritten, infoLog);
        if (strlen(infoLog) >1)
			printf("Program InfoLog:\n%s\n\n", infoLog);
        free(infoLog);
    }
    CheckOGLError();  // Check for OpenGL errors
}





//------------------------------------------------------------------------------------
// освобождаем память
//------------------------------------------------------------------------------------
void vw_ReleaseShader(eGLSL *GLSL)
{
	if (GLSL == 0) return;

	vw_DetachShader(GLSL);

	// открепляем хидеры шейдеров
	if (GLSL->VertexShaderUse) glDetachShader(GLSL->Program, GLSL->VertexShader);
	if (GLSL->FragmentShaderUse) glDetachShader(GLSL->Program, GLSL->FragmentShader);
	// удаляем
	glDeleteShader(GLSL->VertexShader);
	glDeleteShader(GLSL->FragmentShader);
	glDeleteProgram(GLSL->Program);

	if (GLSL->Name != 0){delete [] GLSL->Name; GLSL->Name = 0;}

	// удаляем указатель
	delete GLSL; GLSL = 0;
}








//------------------------------------------------------------------------------------
// освобождаем все шейдеры подключенные к менеджеру
//------------------------------------------------------------------------------------
void vw_ReleaseAllShaders()
{
	// Чистка памяти...
	eGLSL *Tmp = StartGLSLMan;
	while (Tmp != 0)
	{
		eGLSL *Tmp1 = Tmp->Next;
		vw_ReleaseShader(Tmp);
		Tmp = Tmp1;
	}

	StartGLSLMan = 0;
	EndGLSLMan = 0;
	NumGLSLMan = 0;
}







//------------------------------------------------------------------------------------
// подключение к менеджеру
//------------------------------------------------------------------------------------
void vw_AttachShader(eGLSL* GLSL)
{
	if (GLSL == 0) return;

	// первый в списке...
	if (EndGLSLMan == 0)
	{
		GLSL->Prev = 0;
		GLSL->Next = 0;
		NumGLSLMan += 1;
		GLSL->Num = NumGLSLMan;
		StartGLSLMan = GLSL;
		EndGLSLMan = GLSL;
	}
	else // продолжаем заполнение...
	{
		GLSL->Prev = EndGLSLMan;
		GLSL->Next = 0;
		EndGLSLMan->Next = GLSL;
		NumGLSLMan += 1;
		GLSL->Num = NumGLSLMan;
		EndGLSLMan = GLSL;
	}
}





//------------------------------------------------------------------------------------
// отключение от менеджера
//------------------------------------------------------------------------------------
void vw_DetachShader(eGLSL* GLSL)
{
	if (GLSL == 0) return;

	// переустанавливаем указатели...
	if (StartGLSLMan == GLSL) StartGLSLMan = GLSL->Next;
	if (EndGLSLMan == GLSL) EndGLSLMan = GLSL->Prev;


	if (GLSL->Next != 0) GLSL->Next->Prev = GLSL->Prev;
		else if (GLSL->Prev != 0) GLSL->Prev->Next = 0;
	if (GLSL->Prev != 0) GLSL->Prev->Next = GLSL->Next;
		else if (GLSL->Next != 0) GLSL->Next->Prev = 0;
}





//------------------------------------------------------------------------------------
// Нахождение по уникальному номеру...
//------------------------------------------------------------------------------------
eGLSL* vw_FindShaderByNum(int Num)
{
	eGLSL *Tmp = StartGLSLMan;

	while (Tmp != 0)
	{
		eGLSL *Tmp1 = Tmp->Next;
		if (Tmp->Num == Num) return Tmp;
		Tmp = Tmp1;
	}

	return 0;
}






//------------------------------------------------------------------------------------
// Нахождение по имени...
//------------------------------------------------------------------------------------
eGLSL* vw_FindShaderByName(const char *Name)
{
	eGLSL *Tmp = StartGLSLMan;

	while (Tmp != 0)
	{
		eGLSL *Tmp1 = Tmp->Next;
		if( vw_strcmp(Tmp->Name, Name) == 0 ) return Tmp;
		Tmp = Tmp1;
	}

	return 0;
}


























//------------------------------------------------------------------------------------
// создаем шейдерную программу
//------------------------------------------------------------------------------------
eGLSL *vw_CreateShader(const char *ShaderName, const char *VertexShaderFileName, const char *FragmentShaderFileName)
{
	if (VertexShaderFileName == 0 && FragmentShaderFileName == 0) return 0;


	GLint	vertCompiled, fragCompiled;    // status values

	// создаем структуру в памяти
	eGLSL *GLSLtmp = 0;
	GLSLtmp = new eGLSL;
	if (GLSLtmp == 0) return 0;

	// создаем пустые объекты и получаем хидеры на них
    GLSLtmp->VertexShader = glCreateShader(GL_VERTEX_SHADER_ARB);
    GLSLtmp->FragmentShader = glCreateShader(GL_FRAGMENT_SHADER_ARB);


	// загружаем данные в пустые шейдеры

	// вертекстный шейдер
	GLSLtmp->VertexShaderUse = false;
	if (VertexShaderFileName != 0)
	{
		eFILE *VertexFile = 0;
		VertexFile = vw_fopen(VertexShaderFileName);

		if (VertexFile != 0)
		{
			const GLcharARB *TmpGLcharARB =  (const GLcharARB *)VertexFile->Data;
			glShaderSource(GLSLtmp->VertexShader, 1, &TmpGLcharARB, &VertexFile->RealLength);
			vw_fclose(VertexFile);
			GLSLtmp->VertexShaderUse = true;
		}
	}
	// фрагментный шейдер
	GLSLtmp->FragmentShaderUse = false;
	if (FragmentShaderFileName != 0)
	{
		eFILE *FragmentFile = 0;
		FragmentFile = vw_fopen(FragmentShaderFileName);

		if (FragmentFile != 0)
		{
			const GLcharARB *TmpGLcharARB =  (const GLcharARB *)FragmentFile->Data;
			glShaderSource(GLSLtmp->FragmentShader, 1, &TmpGLcharARB, &FragmentFile->RealLength);
			vw_fclose(FragmentFile);
			GLSLtmp->FragmentShaderUse = true;
		}
	}


	// компилируем шейдеры

	if (GLSLtmp->VertexShaderUse)
	{
		glCompileShader(GLSLtmp->VertexShader);
		CheckOGLError();  // Check for OpenGL errors
		glGetShaderiv(GLSLtmp->VertexShader, GL_COMPILE_STATUS, &vertCompiled);
		vw_PrintShaderInfoLog(GLSLtmp->VertexShader, VertexShaderFileName);

		if (!vertCompiled)	return 0;
	}
	if (GLSLtmp->FragmentShaderUse)
	{
		glCompileShader(GLSLtmp->FragmentShader);
		CheckOGLError();  // Check for OpenGL errors
		glGetShaderiv(GLSLtmp->FragmentShader, GL_COMPILE_STATUS, &fragCompiled);
		vw_PrintShaderInfoLog(GLSLtmp->FragmentShader, FragmentShaderFileName);

		if (!fragCompiled)	return 0;
	}


    // создаем программу, чтобы подключить эти шейдеры
    GLSLtmp->Program = glCreateProgram();
    if (GLSLtmp->VertexShaderUse) glAttachShader(GLSLtmp->Program, GLSLtmp->VertexShader);
    if (GLSLtmp->FragmentShaderUse) glAttachShader(GLSLtmp->Program, GLSLtmp->FragmentShader);


	if (VertexShaderFileName == 0)
		printf("Shader ... %s\n", FragmentShaderFileName);
	else
		if (FragmentShaderFileName == 0)
			printf("Shader ... %s\n", VertexShaderFileName);
		else
			printf("Shader ... %s %s\n", VertexShaderFileName, FragmentShaderFileName);


	if (ShaderName != 0)
	{
		GLSLtmp->Name = new char[strlen(ShaderName)+1];
		strcpy(GLSLtmp->Name, ShaderName);
	}
	else
	{
		GLSLtmp->Name = new char[strlen(VertexShaderFileName)+1];
		strcpy(GLSLtmp->Name, VertexShaderFileName);
	}

	vw_AttachShader(GLSLtmp);

	return GLSLtmp;
}






//------------------------------------------------------------------------------------
// линкуем программу, с учетом отбинденных данных
//------------------------------------------------------------------------------------
bool vw_LinkShaderProgram(eGLSL *GLSL)
{
	if (GLSL == 0) return false;

    GLint linked;

    glLinkProgram(GLSL->Program);
    CheckOGLError();  // Check for OpenGL errors
    glGetProgramiv(GLSL->Program, GL_LINK_STATUS, &linked);
    vw_PrintProgramInfoLog(GLSL->Program);

    if (!linked)
        return false;

	return true;
}





//------------------------------------------------------------------------------------
// запускаем шейдер на исполнение
//------------------------------------------------------------------------------------
bool vw_UseShaderProgram(eGLSL *GLSL)
{
	if (GLSL == 0) return false;

    glUseProgram(GLSL->Program);
    CheckOGLError();

	return true;
}





//------------------------------------------------------------------------------------
// останавливаем работу шейдера
//------------------------------------------------------------------------------------
bool vw_StopShaderProgram()
{

    glUseProgram(0);
    CheckOGLError();

	return true;
}





//------------------------------------------------------------------------------------
// Get the location of a uniform variable
//------------------------------------------------------------------------------------
int vw_GetUniformLocation(eGLSL *GLSL, const char *name)
{

    int loc;

    loc = glGetUniformLocation(GLSL->Program, name);

    if (loc == -1)
        fprintf(stderr, "No such uniform named \"%s\"\n", name);

    CheckOGLError();  // Check for OpenGL errors
    return loc;
}




//------------------------------------------------------------------------------------
// установка значения параметра
//------------------------------------------------------------------------------------
bool vw_Uniform1i(eGLSL *GLSL, int UniformLocation, int data)
{
	if (GLSL == 0) return false;

	glUniform1i(UniformLocation, data);

	CheckOGLError();  // Check for OpenGL errors

	return true;
}
bool vw_Uniform1i(eGLSL *GLSL, const char *name, int data)
{
	if (GLSL == 0) return false;
	if (name == 0) return false;

	int Loc = vw_GetUniformLocation(GLSL, name);
	if (Loc == -1) return false;

	return vw_Uniform1i(GLSL, Loc, data);
}


bool vw_Uniform1f(eGLSL *GLSL, int UniformLocation, float data)
{
	if (GLSL == 0) return false;

	glUniform1f(UniformLocation, data);

	CheckOGLError();  // Check for OpenGL errors

	return true;
}
bool vw_Uniform1f(eGLSL *GLSL, const char *name, float data)
{
	if (GLSL == 0) return false;
	if (name == 0) return false;

	int Loc = vw_GetUniformLocation(GLSL, name);
	if (Loc == -1) return false;

	return vw_Uniform1f(GLSL, Loc, data);
}


bool vw_Uniform3f(eGLSL *GLSL, int UniformLocation, float data1, float data2, float data3)
{
	if (GLSL == 0) return false;

	glUniform3f(UniformLocation, data1, data2, data3);

	CheckOGLError();  // Check for OpenGL errors

	return true;
}
bool vw_Uniform3f(eGLSL *GLSL, const char *name, float data1, float data2, float data3)
{
	if (GLSL == 0) return false;
	if (name == 0) return false;

	int Loc = vw_GetUniformLocation(GLSL, name);
	if (Loc == -1) return false;

	return vw_Uniform3f(GLSL, Loc, data1, data2, data3);
}


bool vw_Uniform1fv(eGLSL *GLSL, int UniformLocation, int count, float *data)
{
	if (GLSL == 0) return false;

	glUniform1fv(UniformLocation, count, data);

	CheckOGLError();  // Check for OpenGL errors

	return true;
}
bool vw_Uniform1fv(eGLSL *GLSL, const char *name, int count, float *data)
{
	if (GLSL == 0) return false;
	if (name == 0) return false;

	int Loc = vw_GetUniformLocation(GLSL, name);
	if (Loc == -1) return false;

	return vw_Uniform1fv(GLSL, Loc, count, data);
}


bool vw_Uniform4fv(eGLSL *GLSL, int UniformLocation, int count, float *data)
{
	if (GLSL == 0) return false;

	glUniform4fv(UniformLocation, count, data);

	CheckOGLError();  // Check for OpenGL errors

	return true;
}
bool vw_Uniform4fv(eGLSL *GLSL, const char *name, int count, float *data)
{
	if (GLSL == 0) return false;
	if (name == 0) return false;

	int Loc = vw_GetUniformLocation(GLSL, name);
	if (Loc == -1) return false;

	return vw_Uniform4fv(GLSL, Loc, count, data);
}


bool vw_UniformMatrix4fv(eGLSL *GLSL, int UniformLocation, bool transpose, int count, float *data)
{
	if (GLSL == 0) return false;

	glUniformMatrix4fv(UniformLocation, count, transpose, data);

	CheckOGLError();  // Check for OpenGL errors

	return true;
}
bool vw_UniformMatrix4fv(eGLSL *GLSL, const char *name, bool transpose, int count, float *data)
{
	if (GLSL == 0) return false;
	if (name == 0) return false;

	int Loc = vw_GetUniformLocation(GLSL, name);
	if (Loc == -1) return false;

	return vw_UniformMatrix4fv(GLSL, Loc, transpose, count, data);
}

