// Copyright 2013 Google Inc. All Rights Reserved.
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

//
// Routine that maps a Unicode code point to an interchange-valid one
//
// Table that maps MS CP1252 bytes 00-FF to their corresponding Unicode
// code points. C0 and C1 control codes that are not interchange-valid
// are mapped to spaces.


#ifndef I18N_ENCODINGS_CLD2_INTERNAL_FIXUNICODEVALUE_H__
#define I18N_ENCODINGS_CLD2_INTERNAL_FIXUNICODEVALUE_H__

#include "integral_types.h"        // for char32
#include "port.h"

namespace CLD2 {

// Map byte value 0000-00FF to char32
// Maps C0 control codes (other than CR LF HT FF) to space [29 instances including DEL=0x7F]
// Maps C1 control codes to CP1252 [27 instances] or space [5 instances]
static const char32 kMapFullMicrosoft1252OrSpace[256] = {
  0x20,0x20,0x20,0x20, 0x20,0x20,0x20,0x20, 0x20,0x09,0x0a,0x20, 0x0c,0x0d,0x20,0x20, // 00
  0x20,0x20,0x20,0x20, 0x20,0x20,0x20,0x20, 0x20,0x20,0x20,0x20, 0x20,0x20,0x20,0x20,
  0x20,0x21,0x22,0x23, 0x24,0x25,0x26,0x27, 0x28,0x29,0x2a,0x2b, 0x2c,0x2d,0x2e,0x2f,
  0x30,0x31,0x32,0x33, 0x34,0x35,0x36,0x37, 0x38,0x39,0x3a,0x3b, 0x3c,0x3d,0x3e,0x3f,

  0x40,0x41,0x42,0x43, 0x44,0x45,0x46,0x47, 0x48,0x49,0x4a,0x4b, 0x4c,0x4d,0x4e,0x4f, // 40
  0x50,0x51,0x52,0x53, 0x54,0x55,0x56,0x57, 0x58,0x59,0x5a,0x5b, 0x5c,0x5d,0x5e,0x5f,
  0x60,0x61,0x62,0x63, 0x64,0x65,0x66,0x67, 0x68,0x69,0x6a,0x6b, 0x6c,0x6d,0x6e,0x6f,
  0x70,0x71,0x72,0x73, 0x74,0x75,0x76,0x77, 0x78,0x79,0x7a,0x7b, 0x7c,0x7d,0x7e,0x20,

  0x20ac,0x20,0x201a,0x0192, 0x201e,0x2026,0x2020,0x2021,                             // 80
  0x02c6,0x2030,0x0160,0x2039, 0x0152,0x20,0x017d,0x20,
  0x20,0x2018,0x2019,0x201c, 0x201d,0x2022,0x2013,0x2014,
  0x02dc,0x2122,0x0161,0x203a, 0x0153,0x20,0x017e,0x0178,
  0xa0,0xa1,0xa2,0xa3, 0xa4,0xa5,0xa6,0xa7, 0xa8,0xa9,0xaa,0xab, 0xac,0xad,0xae,0xaf, // A0
  0xb0,0xb1,0xb2,0xb3, 0xb4,0xb5,0xb6,0xb7, 0xb8,0xb9,0xba,0xbb, 0xbc,0xbd,0xbe,0xbf,

  0xc0,0xc1,0xc2,0xc3, 0xc4,0xc5,0xc6,0xc7, 0xc8,0xc9,0xca,0xcb, 0xcc,0xcd,0xce,0xcf, // C0
  0xd0,0xd1,0xd2,0xd3, 0xd4,0xd5,0xd6,0xd7, 0xd8,0xd9,0xda,0xdb, 0xdc,0xdd,0xde,0xdf,
  0xe0,0xe1,0xe2,0xe3, 0xe4,0xe5,0xe6,0xe7, 0xe8,0xe9,0xea,0xeb, 0xec,0xed,0xee,0xef,
  0xf0,0xf1,0xf2,0xf3, 0xf4,0xf5,0xf6,0xf7, 0xf8,0xf9,0xfa,0xfb, 0xfc,0xfd,0xfe,0xff,
};

// Guarantees that the resulting output value is interchange valid
//  00-FF; map to spaces or MS CP1252
//  D800-DFFF; surrogates
//  FDD0-FDEF; non-characters
//  xxFFFE-xxFFFF; non-characters
char32 FixUnicodeValue(char32 uv);

}       // End namespace CLD2

#endif  // I18N_ENCODINGS_CLD2_INTERNAL_FIXUNICODEVALUE_H__

