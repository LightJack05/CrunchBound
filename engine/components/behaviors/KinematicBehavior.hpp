#ifndef KINEMATICBEHAVIOR_HPP
#define KINEMATICBEHAVIOR_HPP

#include "Behavior.hpp"
class KinematicBehavior : public Behavior {
    public:
        void OnTick() override;
        void OnStart() override;
};

#endif // KINEMATICBEHAVIOR_HPP
