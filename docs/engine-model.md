IPhysicsController {
    velX: float
    velY: float
    weight: float
}

ITransform {
    posX: float
    posY: float
    scaleX: float
    scaleY: float
}

GameObject : ITransform, IPhysicsController{
    enabled: bool
    components: Vector<Component>
}

abstract Component {
    enabled: bool
    virtual void OnTick(obj);
    virtual void OnStart(obj);
}


abstract Renderer : Component {
    virtual void render(renderer);
}


RectangleRenderer : Renderer {
    rect: SDL_FRect
    impl render(renderer);
}

/...



abstract GameObjectBehavior : Component {

}

PhysicsBehavior: GameObjectBehavior {

}

CollisionBehavior: PhysicsBehavior{
    collisionEnabled: bool
    respectWalls: bool
    colliderLayers: Vector<int>
    collisionLayer: int
    bounciness: float
}

GravityBehavior: PhysicsBehavior {
    gravityScale: float
    gravityEnabled: bool
}

StaticBehavior: PhysicsBehavior {

}
