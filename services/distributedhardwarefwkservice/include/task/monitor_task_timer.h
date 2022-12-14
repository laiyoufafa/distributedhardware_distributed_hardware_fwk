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

#ifndef OHOS_DISTRIBUTED_HARDWARE_MONITOR_TASK_TIMER_H
#define OHOS_DISTRIBUTED_HARDWARE_MONITOR_TASK_TIMER_H

#include "dh_timer.h"

namespace OHOS {
namespace DistributedHardware {
namespace {
    const std::string MONITOR_TASK_TIMER_ID = "monitor_task_timer_id";
    constexpr int32_t MONITOR_TASK_DELAY_MS = 5 * 1000;
}

class MonitorTaskTimer : public DHTimer {
public:
    MonitorTaskTimer(std::string timerId, int32_t delayTimerMs);
    ~MonitorTaskTimer();

private:
    void ExecuteInner() override;
    void HandleStopTimer() override;
};
} // namespace DistributedHardware
} // namespace OHOS
#endif
