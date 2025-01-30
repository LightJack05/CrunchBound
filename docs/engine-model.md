GameObject<T> {
    posX: float
    posY: float
    scaleX: float
    scaleY: float
    SdlRenderedObject: T
    behaviors: Vector<GameObjectBehavior>
}

GameObjectBehavior {
    virtual void ControllerTickActions(obj);
}

PhysicsBehavior: GameObjectBehavior {
    velX: float
    velY: float
    weight: float
}

CollisionController{
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
}
