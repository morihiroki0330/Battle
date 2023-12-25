 cbuffer ModelCb : register(b0)
{
	float4x4 mWorld;
	float4x4 mView;
	float4x4 mProj;
};

struct SVSIn 
{
	float4 pos 		: POSITION;	
	float3 normal   :NORMAL;
	float2 uv 		: TEXCOORD0;	
	float3 tangent  : TANGENT;
	float3 biNormal : BINORMAL;
};

struct SPSIn 
{
	float4 pos 			: SV_POSITION;	
	float3 normal       :NORMAL;
	float2 uv 			: TEXCOORD0;	
	float3 worldPos     : TEXCOORD1;
	float3 normalInView : TEXCOORD2;
	float3 tangent  : TANGENT;
	float3 biNormal : BINORMAL;
	float4 color : COLOR;
};

struct VertexInput
{
    float3 position : POSITION;
    float2 texCoord : TEXCOORD;
    // 他の頂点データ
};

struct PixelInput
{
    float4 position : SV_POSITION;
    float2 TexCoord : TEXCOORD0;
};

Texture2D<float4> g_albedo : register(t0);				
Texture2D<float4> g_normalMap : register(t1);				
Texture2D<float4> g_specularMap : register(t2); 

Texture2D<float4> g_GroundMap : register(t10);

sampler g_sampler : register(s0);	

SPSIn VSMainCore(SVSIn vsIn, uniform bool hasSkin)
{
	SPSIn psIn;
	float4x4 m;
	m = mWorld;
	psIn.worldPos = vsIn.pos;
	psIn.pos = mul(m, vsIn.pos);
	psIn.pos = mul(mView, psIn.pos);
	psIn.pos = mul(mProj, psIn.pos);
	psIn.normal = mul(mWorld, vsIn.normal);
	psIn.uv = vsIn.uv;
	psIn.normalInView = mul(mView, psIn.normal);
	psIn.tangent = normalize(mul(mWorld, vsIn.tangent));
	psIn.biNormal = normalize(mul(mWorld, vsIn.biNormal));

	return psIn;
}

SPSIn VSMain(SVSIn vsIn)
{
	return VSMainCore(vsIn, false);
}

float4 PSMain(SPSIn psIn,PixelInput piIn) : SV_Target0
{
	float4 TexColor = g_GroundMap.Sample(g_sampler,piIn.TexCoord);

	if(TexColor.r>TexColor.g)
	{
		if(TexColor.r>TexColor.b)
		{
			TexColor = g_GroundMap.Sample(g_sampler,piIn.TexCoord);
		}
	}else{
		if(TexColor.g>TexColor.r)
		{
			if(TexColor.g>TexColor.b)
			{
				TexColor = g_GroundMap.Sample(g_sampler,piIn.TexCoord);
			}
	}else{
			if(TexColor.b>TexColor.g)
			{
				if(TexColor.b>TexColor.r)
				{
					TexColor = g_GroundMap.Sample(g_sampler,piIn.TexCoord);
				}
			}
		}
	}
	return TexColor;
}