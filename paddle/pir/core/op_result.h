// Copyright (c) 2023 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "paddle/pir/core/value.h"
namespace pir {

namespace detail {
class OpResultImpl;
}  // namespace detail

///
/// \brief OpResult class represents the value defined by a result of operation.
/// This class only provides interfaces, for specific implementation, see Impl
/// class.
///
class IR_API OpResult : public Value {
 public:
  OpResult() = default;
  Operation *owner() const;
  uint32_t GetResultIndex() const;
  bool operator==(const OpResult &other) const;
  // OpResult(const detail::OpResultImpl *impl);  // NOLINT

  // This func will remove in next pr.
  OpResult(const detail::ValueImpl *impl) : Value(impl) {}  // NOLINT

 private:
  friend Operation;
  static uint32_t GetValidInlineIndex(uint32_t index);
  // Access classof annd dyn_cast_from.
  friend Value;
  static bool classof(Value value);
  static OpResult dyn_cast_from(Value value);
};

}  // namespace pir
