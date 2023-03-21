/*
 * Copyright (c) 2022-2023 Huawei Device Co., Ltd.
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

#ifndef OHOS_DISTRIBUTED_HARDWARE_LOW_LATENCY_LISTENER_TEST_H
#define OHOS_DISTRIBUTED_HARDWARE_LOW_LATENCY_LISTENER_TEST_H

#include <string>
#include <memory>
#include <gtest/gtest.h>

#define private public
#include "low_latency_listener.h"
#include "low_latency_timer.h"
#undef private
#include "distributed_hardware_errno.h"

namespace OHOS {
namespace DistributedHardware {
class LowLatencyListenerTest : public testing::Test {
public:
    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp();
    void TearDown();
    sptr<LowLatencyListener> Listener_ = nullptr;
};
} // namespace DistributedHardware
} // namespace OHOS
#endif // OHOS_DISTRIBUTED_HARDWARE_LOW_LATENCY_LISTENER_TEST_H