GameObject<T> {
    enabled: bool
    posX: float
    posY: float
    scaleX: float
    scaleY: float
    SdlRenderedObject: T
    behaviors: Vector<GameObjectBehavior>
}

IPhysicsController {
    velX: float
    velY: float
    weight: float
}

KinematicGameObject<T>: GameObject<T>, IPhysicsController{
        
}


GameObjectBehavior {
    enabled: bool
    virtual void OnTick(obj);
    virtual void OnStart(obj);
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

ElasticBehavior: PhysicsBehavior {
}

GravityBehavior: PhysicsBehavior {
    gravityScale: float
    gravityEnabled: bool
}

StaticBehavior: PhysicsBehavior {
