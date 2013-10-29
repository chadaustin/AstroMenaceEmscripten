#version 120

//  directional & point light per pixel + normal mapping

uniform sampler2D Texture1, Texture2, NormalMap;
uniform int NeedMultitexture;
uniform int NeedNormalMapping;

uniform int DirectLightCount;
uniform int PointLightCount;

// тянем нормаль (уже нормализованную)
varying vec3 pNormal;
varying vec3 pTangent;
varying vec3 pBinormal;

// тянем вертекс
varying vec3 Vertex;


void main()
{
	// меняем нормаль с учетом нормал мепа, если нужно
	vec3 Normal = pNormal;
	if (NeedNormalMapping == 1)
	{
		mat3 TBN = mat3(pTangent, pBinormal, pNormal);
		Normal = normalize(TBN * normalize(texture2D(NormalMap, gl_TexCoord[0].st).xyz * 2.0 - 1.0));
	}


	vec3 halfV;
	float NdotL, NdotHV;

	// глобальный эмбиент учитываем сразу
	vec4 color = vec4(0.0,0.0,0.0,1.0);
	color += gl_LightModel.ambient * gl_FrontMaterial.ambient;

	// обрабатываем все источники света
	// делаем directional & point light per pixel (а не directional & point light per vertex)

	// делаем directional light per pixel
	for (int i=0; i<DirectLightCount; i++)
	{
		// учитываем ambient
		color += gl_FrontMaterial.ambient * gl_LightSource[i].ambient;

		NdotL = max(dot(Normal, normalize(gl_LightSource[i].position.xyz)),0.0);
		if (NdotL > 0.0) 
		{
			color += gl_FrontMaterial.diffuse * gl_LightSource[i].diffuse * NdotL;
		//  specular составляющая
			halfV = normalize(gl_LightSource[i].halfVector.xyz);
			NdotHV = max(dot(Normal, halfV),0.0);
			color += gl_FrontMaterial.specular * gl_LightSource[i].specular * pow(NdotHV, gl_FrontMaterial.shininess);
		}
	}

	// делаем point light per pixel
	for (int i=DirectLightCount; i<DirectLightCount+PointLightCount; i++)
	{
		vec3 Direction = vec3(gl_LightSource[i].position.xyz-Vertex);

		NdotL = max(dot(Normal, normalize(Direction)),0.0);
		if (NdotL > 0.0) 
		{
			float Dist = length(Direction);

		// считаем коэф. ослабление источка
			float att = 1.0 / (gl_LightSource[i].constantAttenuation +
					gl_LightSource[i].linearAttenuation * Dist +
					gl_LightSource[i].quadraticAttenuation * Dist * Dist);
		// учитываем diffuse и ambient состовляющие
			color += att * (gl_FrontMaterial.diffuse * gl_LightSource[i].diffuse * NdotL + gl_FrontMaterial.ambient * gl_LightSource[i].ambient);
		//  specular составляющая
			halfV = normalize(gl_LightSource[i].halfVector.xyz);
			NdotHV = max(dot(Normal, halfV),0.0);
			color += att * gl_FrontMaterial.specular * gl_LightSource[i].specular * pow(NdotHV,gl_FrontMaterial.shininess);
		}
	}


	gl_FragColor = clamp(color,0.0,1.0)*texture2D(Texture1,gl_TexCoord[0].st);
	// смотрим, если надо Texture2
	if (NeedMultitexture == 1)
		gl_FragColor = clamp(gl_FragColor+texture2D(Texture2,gl_TexCoord[0].st), 0.0, 1.0);
}
