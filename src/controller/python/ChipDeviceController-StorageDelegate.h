/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once

#include <map>
#include <string>

#include <controller/CHIPPersistentStorageDelegate.h>

class PythonPersistentStorageDelegate;

typedef void (*GetKeyValueFunct)(const uint8_t * key, uint8_t * value, uint16_t * size);
typedef void (*SetKeyValueFunct)(const uint8_t * key, const uint8_t * value);
typedef void (*DeleteKeyValueFunct)(const uint8_t * key);

namespace chip {
namespace Controller {

class PythonPersistentStorageDelegate : public PersistentStorageDelegate
{
public:
    PythonPersistentStorageDelegate() {}
    void SetDelegate(PersistentStorageResultDelegate * delegate) override;
    void GetKeyValue(const char * key) override;
    CHIP_ERROR GetKeyValue(const char * key, char * value, uint16_t & size) override;
    void SetKeyValue(const char * key, const char * value) override;
    void DeleteKeyValue(const char * key) override;

private:
    PersistentStorageResultDelegate * mDelegate;
    std::map<std::string, std::string> mStorage;
};

} // namespace Controller
} // namespace chip
