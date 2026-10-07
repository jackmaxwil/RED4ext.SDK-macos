#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/Matrix.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/ISystemObject.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/PhysicsJointAngularLimitPair.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/PhysicsJointDrive.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/PhysicsJointDriveVelocity.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/PhysicsJointLimitConePair.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/PhysicsJointLinearLimit.hpp>

namespace RED4ext
{
namespace physics { struct PhysicalJointPin; }

namespace physics
{
struct __declspec(align(0x10)) SystemJoint : physics::ISystemObject
{
    static constexpr const char* NAME = "physicsSystemJoint";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    physics::PhysicsJointLinearLimit linearLimit; // 38
    physics::PhysicsJointAngularLimitPair twistLimit; // 60
    physics::PhysicsJointLimitConePair swingLimit; // 88
    physics::PhysicsJointDrive driveX; // B0
    physics::PhysicsJointDrive driveY; // C0
    physics::PhysicsJointDrive driveZ; // D0
    physics::PhysicsJointDrive driveSwing; // E0
    physics::PhysicsJointDrive driveTwist; // F0
    physics::PhysicsJointDrive driveSLERP; // 100
    physics::PhysicsJointDriveVelocity driveVelocity; // 110
    Matrix drivePosition; // 130
    Handle<physics::PhysicalJointPin> pinA; // 170
    Handle<physics::PhysicalJointPin> pinB; // 180
    Matrix localToWorld; // 190
    float breakingForce; // 1D0
    float breakingTorque; // 1D4
    float linearTolerance; // 1D8
    float angularTolerance; // 1DC
    bool projectionEnabled; // 1E0
    bool isBreakable; // 1E1
    uint8_t unk1E2[0x1F0 - 0x1E2]; // 1E2
#else
    physics::PhysicsJointLinearLimit linearLimit; // 38
    physics::PhysicsJointAngularLimitPair twistLimit; // 60
    physics::PhysicsJointLimitConePair swingLimit; // 90
    physics::PhysicsJointDrive driveX; // C0
    physics::PhysicsJointDrive driveY; // D0
    physics::PhysicsJointDrive driveZ; // E0
    physics::PhysicsJointDrive driveSwing; // F0
    physics::PhysicsJointDrive driveTwist; // 100
    physics::PhysicsJointDrive driveSLERP; // 110
    physics::PhysicsJointDriveVelocity driveVelocity; // 120
    Matrix drivePosition; // 140
    Handle<physics::PhysicalJointPin> pinA; // 180
    Handle<physics::PhysicalJointPin> pinB; // 190
    Matrix localToWorld; // 1A0
    float breakingForce; // 1E0
    float breakingTorque; // 1E4
    float linearTolerance; // 1E8
    float angularTolerance; // 1EC
    bool projectionEnabled; // 1F0
    bool isBreakable; // 1F1
    uint8_t unk1F2[0x200 - 0x1F2]; // 1F2
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SystemJoint, 0x1F0);
RED4EXT_ASSERT_OFFSET(SystemJoint, linearLimit, 0x38);
RED4EXT_ASSERT_OFFSET(SystemJoint, twistLimit, 0x60);
RED4EXT_ASSERT_OFFSET(SystemJoint, swingLimit, 0x88);
RED4EXT_ASSERT_OFFSET(SystemJoint, driveX, 0xB0);
RED4EXT_ASSERT_OFFSET(SystemJoint, driveY, 0xC0);
RED4EXT_ASSERT_OFFSET(SystemJoint, driveZ, 0xD0);
RED4EXT_ASSERT_OFFSET(SystemJoint, driveSwing, 0xE0);
RED4EXT_ASSERT_OFFSET(SystemJoint, driveTwist, 0xF0);
RED4EXT_ASSERT_OFFSET(SystemJoint, driveSLERP, 0x100);
RED4EXT_ASSERT_OFFSET(SystemJoint, driveVelocity, 0x110);
RED4EXT_ASSERT_OFFSET(SystemJoint, drivePosition, 0x130);
RED4EXT_ASSERT_OFFSET(SystemJoint, pinA, 0x170);
RED4EXT_ASSERT_OFFSET(SystemJoint, pinB, 0x180);
RED4EXT_ASSERT_OFFSET(SystemJoint, localToWorld, 0x190);
RED4EXT_ASSERT_OFFSET(SystemJoint, breakingForce, 0x1D0);
RED4EXT_ASSERT_OFFSET(SystemJoint, breakingTorque, 0x1D4);
RED4EXT_ASSERT_OFFSET(SystemJoint, linearTolerance, 0x1D8);
RED4EXT_ASSERT_OFFSET(SystemJoint, angularTolerance, 0x1DC);
RED4EXT_ASSERT_OFFSET(SystemJoint, projectionEnabled, 0x1E0);
RED4EXT_ASSERT_OFFSET(SystemJoint, isBreakable, 0x1E1);
#else
RED4EXT_ASSERT_SIZE(SystemJoint, 0x200);
#endif
} // namespace physics
using physicsSystemJoint = physics::SystemJoint;
} // namespace RED4ext

// clang-format on
