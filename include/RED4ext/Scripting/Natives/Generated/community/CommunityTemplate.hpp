#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
namespace community { struct CommunityTemplateData; }

namespace community
{
struct CommunityTemplate : CResource
{
    static constexpr const char* NAME = "communityCommunityTemplate";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Handle<community::CommunityTemplateData> communityTemplate; // 40
#else
    Handle<community::CommunityTemplateData> communityTemplate; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CommunityTemplate, 0x50);
RED4EXT_ASSERT_OFFSET(CommunityTemplate, communityTemplate, 0x40);
#else
RED4EXT_ASSERT_SIZE(CommunityTemplate, 0x50);
#endif
} // namespace community
using communityCommunityTemplate = community::CommunityTemplate;
} // namespace RED4ext

// clang-format on
