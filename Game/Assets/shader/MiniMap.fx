/*!
 * @brief	�X�v���C�g�p�̃V�F�[�_�[�B
 */

cbuffer cb : register(b0)
{
	float4x4 mvp;
	float4 mulColor;
};

struct VSInput{
	float4 pos : POSITION;
	float2 uv  : TEXCOORD0;
};

struct PSInput
{
	float4 pos : SV_POSITION;
	float2 uv  : TEXCOORD0;
};

cbuffer CharacterCb : register(b1)
{
    float2 CharacterUV;  
};

Texture2D<float4> Texture : register(t0);
Texture2D<float4> g_GrassMap : register(t1);
Texture2D<float4> g_SoilMap : register(t2);
Texture2D<float4> g_SeeMap : register(t3);

sampler Sampler : register(s0);

PSInput VSMain(VSInput In) 
{
	PSInput psIn;
	psIn.pos = mul( mvp, In.pos );
	psIn.uv = In.uv;
	return psIn;
}
float4 PSMain( PSInput In ) : SV_Target0
{
	float2 Size = float2(4000.0, 4000.0);
    float2 ExSize = float2(380.0, 380.0);

    float2 Character = CharacterUV;
    float2 CenterCord = In.uv - Character;
    float2 ExCord = (CenterCord * ExSize / Size) + Character;

    float4 TexColor = Texture.Sample(Sampler, ExCord);

	if(TexColor.r>TexColor.g)
	{
		if(TexColor.r>TexColor.b)
		{
			TexColor = g_SoilMap.Sample(Sampler,ExCord);
			TexColor.rgb = pow(TexColor.rgb, 1.0 / 2.2);
		}
	}
	else{
		if(TexColor.g>TexColor.r)
		{
			if(TexColor.g>TexColor.b)
			{
				TexColor = g_GrassMap.Sample(Sampler,ExCord);
				TexColor.rgb = pow(TexColor.rgb, 1.0 / 2.2);
			}
	}else{
			if(TexColor.b>TexColor.g)
			{
				if(TexColor.b>TexColor.r)
				{
					TexColor = g_SeeMap.Sample(Sampler,ExCord);
					TexColor.rgb = pow(TexColor.rgb, 1.0 / 2.2);
				}
			}
		}
	}
    float4 finalColor = TexColor * mulColor;
	return finalColor;
}