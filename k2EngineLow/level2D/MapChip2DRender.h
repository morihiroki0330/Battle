#pragma once
namespace nsK2EngineLow {
	struct Level2DRenderObjectData;
	/// <summary>
	/// マップチップ2D。
	/// </summary>
	class MapChip2DRender : public Noncopyable
	{
	public:
		/// <summary>
		/// 初期化。
		/// </summary>
		/// <param name="objData">レベル2Dデータ。</param>
		void Init(Level2DRenderObjectData* objData);
		/// <summary>
		/// 更新処理。
		/// </summary>
		void Update()
		{
			m_spriteRender.Update();
		}
		/// <summary>
		/// スプライトを描画する。
		/// </summary>
		/// <param name="renderContext">レンダーコンテキスト。</param>
		void Draw(RenderContext& renderContext)
		{
			m_spriteRender.Draw(renderContext);
		}
	private:
		SpriteRender m_spriteRender;			//スプライト。
	};
}


