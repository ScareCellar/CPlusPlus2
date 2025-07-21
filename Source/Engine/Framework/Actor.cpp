#include "Actor.h"
#include "../Renderer/Model.h"
#include "../Renderer/Renderer.h"

namespace blood {


    void Actor::Update(float dt)
    {
        //
    }

    void Actor::Draw(Renderer& renderer)
    {
        m_model->Draw(renderer, m_transform);
    }
}