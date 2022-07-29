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

#ifndef PUBLISHER_LISTENER_STUB_H
#define PUBLISHER_LISTENER_STUB_H

#include "i_publisher_listener.h"

#include "iremote_stub.h"

namespace OHOS {
namespace DistributedHardware {
class PublisherListenerStub : public IRemoteStub<IPublisherListener> {
public:
    PublisherListenerStub();
    virtual ~PublisherListenerStub() override;
    int32_t OnRemoteRequest(uint32_t code, MessageParcel &data, MessageParcel &reply, MessageOption &option) override;

private:
    DISALLOW_COPY_AND_MOVE(PublisherListenerStub);
};
} // namespace DistributedHardware
} // namespace OHOS
#endif