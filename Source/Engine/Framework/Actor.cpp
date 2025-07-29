#include "Actor.h"
#include "../Renderer/Model.h"
#include "../Renderer/Renderer.h"

namespace blood {


    void Actor::Update(float dt)
    {
        m_transform.position += velocity * dt;
        velocity = velocity * (1.0f - damping * dt);
    }

    void Actor::Draw(Renderer& renderer)
    {
        m_model->Draw(renderer, m_transform);
    }
}