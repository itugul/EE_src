#ifndef EXPLOSION_EFFECT_H
#define EXPLOSION_EFFECT_H

#include "spaceObject.h"

class ExplosionEffect : public SpaceObject, public Updatable
{
    constexpr static float maxLifetime = 2.0;
    constexpr static int particleCount = 1000;
    
    float lifetime;
    float size;
    string explosion_sound;
    sf::Vector3f particleDirections[particleCount];
    bool on_radar;
public:
    P<SpaceObject> instigator;
    ExplosionEffect();

#if FEATURE_3D_RENDERING
    virtual void draw3DTransparent();
#endif
    virtual void drawOnRadar(sf::RenderTarget& window, sf::Vector2f position, float scale, bool longRange);
    virtual void update(float delta);
    
    void setInstigator(P<SpaceObject> obj) { this->instigator = obj; }
    void setSize(float size) { this->size = size; }
    void setExplosionSound(string sound) { this->explosion_sound = sound; }
    void setOnRadar(bool on_radar) { this->on_radar = on_radar; }
};

#endif//EXPLOSION_EFFECT_H
