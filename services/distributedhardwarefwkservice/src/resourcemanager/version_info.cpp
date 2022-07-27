/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "version_info.h"

#include <string>

#include "nlohmann/json.hpp"

#include "anonymous_string.h"
#include "constants.h"
#include "distributed_hardware_errno.h"
#include "distributed_hardware_log.h"

namespace OHOS {
namespace DistributedHardware {
#undef DH_LOG_TAG
#define DH_LOG_TAG "VersionInfo"

void VersionInfo::FromJsonString(const std::string &jsonStr)
{
    nlohmann::json jsonObj = nlohmann::json::parse(jsonStr);
    FromJson(jsonObj, *this);
}

std::string VersionInfo::ToJsonString() const
{
    nlohmann::json jsonObj;
    ToJson(jsonObj, *this);
    return jsonObj.dump();
}

void ToJson(nlohmann::json &jsonObject, const VersionInfo &versionInfo)
{
    jsonObject[DEV_ID] = versionInfo.deviceId;
    jsonObject[DH_VER] = versionInfo.dhVersion;

    nlohmann::json compVers;
    for (const auto &compVersion : versionInfo.compVersions) {
        nlohmann::json compVer;
        compVer[NAME] = compVersion.second.name;
        compVer[TYPE] = compVersion.second.dhType;
        compVer[HANDLER] = compVersion.second.handlerVersion;
        compVer[SOURCE_VER] = compVersion.second.sourceVersion;
        compVer[SINK_VER] = compVersion.second.sinkVersion;
        compVers.push_back(compVer);
    }

    jsonObject[COMP_VER] = compVers;
}

void FromJson(const nlohmann::json &jsonObject, CompVersion &compVer)
{
    if (jsonObject.find(NAME) != jsonObject.end()) {
        compVer.name = jsonObject.at(NAME).get<std::string>();
    }
    if (jsonObject.find(TYPE) != jsonObject.end()) {
        compVer.dhType = jsonObject.at(TYPE).get<DHType>();
    }
    if (jsonObject.find(HANDLER) != jsonObject.end()) {
        compVer.handlerVersion = jsonObject.at(HANDLER).get<std::string>();
    }
    if (jsonObject.find(SOURCE_VER) != jsonObject.end()) {
        compVer.sourceVersion = jsonObject.at(SOURCE_VER).get<std::string>();
    }
    if (jsonObject.find(SINK_VER) != jsonObject.end()) {
        compVer.sinkVersion = jsonObject.at(SINK_VER).get<std::string>();
    }
}

void FromJson(const nlohmann::json &jsonObject, VersionInfo &versionInfo)
{
    if (jsonObject.find(DEV_ID) != jsonObject.end()) {
        versionInfo.deviceId = jsonObject.at(DEV_ID).get<std::string>();
    }

    if (jsonObject.find(DH_VER) != jsonObject.end()) {
        versionInfo.dhVersion = jsonObject.at(DH_VER).get<std::string>();
    }

    if (jsonObject.find(COMP_VER) != jsonObject.end()) {
        for (const auto &compVerObj : jsonObject.at(COMP_VER)) {
            CompVersion compVer;
            FromJson(compVerObj, compVer);
            versionInfo.compVersions.insert(std::pair<DHType, CompVersion>(compVer.dhType, compVer));
        }
    }
}
} // namespace DistributedHardware
} // namespace OHOS