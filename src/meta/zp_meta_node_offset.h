// Copyright 2017 Qihoo
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http:// www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef SRC_META_ZP_META_NODE_OFFSET_H_
#define SRC_META_ZP_META_NODE_OFFSET_H_
#include <string>
#include <map>
#include "src/meta/zp_meta.pb.h"

struct NodeOffset {
  int32_t filenum;
  int64_t offset;

  NodeOffset()
    : filenum(0),
    offset(0) {}

  NodeOffset(int32_t n, int64_t o)
    : filenum(n),
    offset(o) {}

  void Clear() {
    filenum = 0;
    offset = 0;
  }

  bool operator== (const NodeOffset& rhs) const {
    return (filenum == rhs.filenum && offset == rhs.offset);
  }
  bool operator!= (const NodeOffset& rhs) const {
    return (filenum != rhs.filenum || offset != rhs.offset);
  }
  bool operator< (const NodeOffset& rhs) const {
    return (filenum < rhs.filenum ||
        (filenum == rhs.filenum && offset < rhs.offset));
  }
  bool operator<= (const NodeOffset& rhs) const {
    return (filenum < rhs.filenum ||
        (filenum == rhs.filenum && offset <= rhs.offset));
  }
  bool operator> (const NodeOffset& rhs) const {
    return (filenum > rhs.filenum ||
        (filenum == rhs.filenum && offset > rhs.offset));
  }
  bool operator>= (const NodeOffset& rhs) const {
    return (filenum > rhs.filenum ||
        (filenum == rhs.filenum && offset >= rhs.offset));
  }
};

#endif  // SRC_META_ZP_META_NODE_OFFSET_H_
