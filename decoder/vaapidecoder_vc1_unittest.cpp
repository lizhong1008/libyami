/*
 * Copyright 2016 Intel Corporation
 *
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

// primary header
#include "vaapidecoder_vc1.h"

// library headers
#include "common/factory_unittest.h"

// system headers
#include <tr1/array>

namespace YamiMediaCodec {

const static std::tr1::array<uint8_t, 5797> g_SimpleVC1 = {
    0x80, 0x6b, 0x97, 0x00, 0xf3, 0xe3, 0xc1, 0x06, 0xdb, 0x3e, 0x88, 0x60, 0x8c, 0xec, 0x31, 0x92,
    0xa0, 0xaa, 0x42, 0xf6, 0x4d, 0xf7, 0x01, 0xcc, 0x73, 0x00, 0x79, 0xea, 0xc8, 0x3a, 0xb9, 0x53,
    0xb0, 0x1c, 0xb6, 0x21, 0x99, 0x60, 0x95, 0x3f, 0x38, 0x53, 0x10, 0x79, 0xa5, 0x5a, 0x8b, 0x01,
    0xc1, 0x76, 0xe9, 0xf1, 0x03, 0xe6, 0xdd, 0xb1, 0x88, 0xf8, 0x70, 0x88, 0xac, 0xce, 0x12, 0x99,
    0x59, 0xd5, 0x42, 0x9c, 0xa5, 0x82, 0x83, 0xc7, 0x54, 0xc5, 0xa4, 0x96, 0xf0, 0xbe, 0x05, 0x9d,
    0x77, 0xa6, 0xfc, 0xe8, 0x4e, 0x0a, 0xb0, 0x6c, 0xc2, 0x1b, 0xed, 0x0b, 0xc7, 0xcb, 0x57, 0x2e,
    0x0b, 0x11, 0xde, 0x61, 0x0d, 0x07, 0x06, 0xc6, 0x7b, 0x3b, 0x1f, 0x72, 0x2f, 0x33, 0x09, 0xf1,
    0x3f, 0xb9, 0x86, 0x01, 0x5e, 0xbe, 0xa0, 0x0b, 0x8f, 0x21, 0x68, 0xe3, 0x01, 0x8b, 0x6d, 0x1b,
    0x7b, 0x56, 0x7c, 0xba, 0x69, 0x94, 0xc7, 0x35, 0xb3, 0x89, 0x89, 0xa1, 0x2d, 0x16, 0x5f, 0x2c,
    0x41, 0x8a, 0x22, 0x64, 0xdf, 0x26, 0x7a, 0x30, 0x2f, 0xce, 0x4f, 0x05, 0xd8, 0x6c, 0x05, 0x23,
    0xac, 0x62, 0xbc, 0x12, 0x32, 0x59, 0x1a, 0x4f, 0x0a, 0xeb, 0x3c, 0x32, 0x00, 0xa2, 0x31, 0xbd,
    0x77, 0x42, 0x49, 0xb1, 0x6a, 0xc2, 0x07, 0x59, 0xe0, 0xd2, 0x88, 0x92, 0x6f, 0xfa, 0x13, 0x1b,
    0xec, 0x4b, 0xd8, 0x85, 0xc2, 0x7a, 0x36, 0xee, 0x8a, 0xbf, 0xa4, 0x91, 0xb7, 0xb6, 0x5b, 0xe0,
    0x45, 0x99, 0x80, 0x82, 0x26, 0xd0, 0x44, 0x7a, 0x10, 0xc6, 0x48, 0x3f, 0x53, 0x8e, 0x30, 0x13,
    0x87, 0xf6, 0x26, 0x34, 0xfc, 0x8d, 0x89, 0x6c, 0xd2, 0x9a, 0xbc, 0x77, 0x1b, 0x80, 0x08, 0x18,
    0x62, 0x31, 0xb5, 0x79, 0xc7, 0x8f, 0xf3, 0x83, 0x12, 0x11, 0xd3, 0x84, 0x5e, 0x18, 0x6e, 0xa1,
    0x0c, 0xb6, 0xc1, 0x2b, 0x36, 0x02, 0x8d, 0x36, 0x09, 0xe8, 0x95, 0x8a, 0xed, 0xb8, 0x0a, 0x70,
    0xa0, 0x1e, 0xbb, 0xe8, 0x85, 0xcd, 0xc5, 0xc5, 0x93, 0x31, 0x22, 0x73, 0x4a, 0xa0, 0xf4, 0x0b,
    0xd2, 0xee, 0xb7, 0x0b, 0x4d, 0x08, 0xbe, 0xfe, 0x5c, 0x33, 0x02, 0x10, 0x63, 0xf8, 0xc1, 0x44,
    0x36, 0x5a, 0x13, 0xa9, 0x72, 0x58, 0x47, 0x76, 0x0f, 0xac, 0x16, 0x39, 0xe5, 0x28, 0x90, 0x0c,
    0x7a, 0x4b, 0xc9, 0xad, 0xb1, 0xf2, 0xb9, 0xd5, 0x62, 0x54, 0xb1, 0xa3, 0xc5, 0x38, 0x8c, 0xe4,
    0x90, 0x99, 0xe3, 0xa4, 0x58, 0xe6, 0x38, 0xec, 0xf0, 0x4e, 0x7d, 0xbc, 0x55, 0x31, 0x82, 0x30,
    0x4a, 0x0f, 0xa1, 0x2c, 0xd1, 0xce, 0x3b, 0x41, 0xfe, 0xda, 0x1c, 0x98, 0x84, 0x2c, 0x19, 0x16,
    0x94, 0x68, 0x16, 0x05, 0x06, 0xe1, 0xf0, 0x28, 0xc4, 0x39, 0x43, 0xd9, 0x69, 0xbe, 0x08, 0x7f,
    0xca, 0xd0, 0xbc, 0x57, 0x05, 0x75, 0x07, 0xa8, 0x20, 0x93, 0xba, 0x23, 0x47, 0x06, 0xb4, 0x19,
    0xfb, 0x68, 0x73, 0xd5, 0x41, 0x1a, 0xc9, 0xa4, 0xa6, 0x20, 0xdc, 0xcc, 0xaa, 0x6b, 0xfb, 0x75,
    0x64, 0x7a, 0xaa, 0xb3, 0xa8, 0x18, 0x51, 0x1b, 0xdc, 0x05, 0x7c, 0x61, 0x48, 0x74, 0x31, 0x64,
    0xca, 0x9a, 0xa5, 0x32, 0xeb, 0xb9, 0x50, 0x77, 0x9b, 0x70, 0x83, 0xaf, 0x8c, 0xb0, 0x60, 0x19,
    0xc4, 0x5f, 0xa3, 0xe0, 0x3e, 0x4b, 0x49, 0x72, 0xac, 0x11, 0x95, 0x54, 0x59, 0x75, 0xe9, 0x5e,
    0x6b, 0x9b, 0x5c, 0xe9, 0x2e, 0xea, 0xa5, 0xf3, 0x5d, 0x57, 0x0f, 0x1c, 0x8f, 0xfb, 0x7e, 0x4f,
    0x8b, 0xcc, 0xf8, 0x2e, 0xb9, 0xe8, 0x09, 0x24, 0xdb, 0xf0, 0x46, 0x2a, 0xa8, 0x64, 0xce, 0xe6,
    0x8d, 0x1e, 0x83, 0x1a, 0x3d, 0x06, 0x87, 0x8c, 0xe1, 0x31, 0x4c, 0xf4, 0xba, 0xc1, 0x00, 0x4b,
    0xed, 0x10, 0x98, 0xe3, 0x39, 0x14, 0x79, 0xaf, 0xc8, 0x30, 0x31, 0x9b, 0x26, 0x83, 0x4f, 0x89,
    0x54, 0x91, 0xcc, 0x13, 0x04, 0x61, 0xe1, 0x8f, 0xd6, 0xbe, 0xe9, 0xc5, 0xed, 0xd0, 0xd4, 0xd8,
    0xde, 0xf7, 0xef, 0x0c, 0x91, 0x65, 0xbd, 0x27, 0xe5, 0xe2, 0xc7, 0x82, 0x1b, 0x7a, 0xb0, 0xa0,
    0xe2, 0x1b, 0x61, 0xe3, 0x88, 0xc2, 0xde, 0x25, 0x28, 0xc6, 0x73, 0x71, 0x8c, 0x1e, 0xf0, 0x33,
    0xb8, 0x63, 0x1c, 0x80, 0x9d, 0xfd, 0x8c, 0x64, 0x8e, 0x38, 0xc4, 0x40, 0x70, 0x36, 0x98, 0x92,
    0x1b, 0x68, 0xe3, 0x7d, 0xd1, 0x37, 0x50, 0x2d, 0x91, 0x7d, 0x79, 0x94, 0x88, 0x42, 0x0f, 0x15,
    0xaf, 0x21, 0x8c, 0x15, 0x83, 0xb2, 0xc5, 0xd5, 0x13, 0x1e, 0xe2, 0x89, 0x6f, 0xef, 0x5d, 0x8b,
    0x66, 0xd5, 0xb6, 0xbc, 0xce, 0xda, 0x68, 0xf1, 0x75, 0x44, 0x61, 0xc5, 0xc3, 0xea, 0xb4, 0x01,
    0xf3, 0x66, 0x85, 0x14, 0xac, 0x17, 0xa0, 0xd5, 0xd1, 0xd0, 0x17, 0x8d, 0xe0, 0xea, 0xb2, 0xd0,
    0x28, 0xfa, 0xe3, 0xdc, 0xea, 0x09, 0xf3, 0x45, 0x9b, 0xda, 0xa2, 0x82, 0x16, 0xe4, 0x1b, 0x50,
    0xb7, 0x3c, 0x91, 0xb7, 0xd5, 0x77, 0x98, 0x44, 0x27, 0xaf, 0xcc, 0xaa, 0x8a, 0x85, 0x24, 0xc1,
    0xb6, 0x59, 0x6c, 0x09, 0xbe, 0xe6, 0x83, 0xe9, 0x69, 0x20, 0x73, 0x1b, 0x17, 0xfc, 0xc3, 0x99,
    0x94, 0xfa, 0xba, 0x0b, 0xe4, 0x6f, 0xd5, 0xa9, 0xb0, 0x66, 0xe6, 0x60, 0x0a, 0x14, 0x3c, 0x09,
    0x42, 0x7a, 0xfc, 0xca, 0xab, 0x42, 0x35, 0xd3, 0x02, 0xb7, 0x0d, 0x38, 0x7b, 0xb0, 0xa9, 0x38,
    0x50, 0x3e, 0xc7, 0xdd, 0x15, 0x31, 0x95, 0x10, 0x00, 0x18, 0xe6, 0xc1, 0x41, 0xf8, 0xea, 0x88,
    0xa5, 0x27, 0x26, 0xad, 0x1d, 0x6a, 0x9b, 0xad, 0x31, 0xd6, 0x6a, 0x4a, 0xab, 0xbe, 0xa6, 0x6c,
    0x90, 0x3b, 0x67, 0xe4, 0xd0, 0x93, 0x54, 0x59, 0x38, 0x64, 0x64, 0x67, 0x1a, 0x24, 0x3f, 0x20,
    0x7c, 0x48, 0x38, 0xd4, 0xe2, 0x4d, 0x86, 0x26, 0x41, 0xe9, 0x1b, 0xef, 0x09, 0x07, 0x00, 0xa7,
    0x19, 0x73, 0xab, 0xdb, 0x1c, 0x4b, 0x13, 0x25, 0xe6, 0x0a, 0x23, 0x75, 0x82, 0xc1, 0x06, 0xbc,
    0x77, 0x91, 0xc8, 0x76, 0x91, 0x2c, 0x49, 0xce, 0x8d, 0x17, 0xd7, 0x1b, 0x37, 0x17, 0x1f, 0x15,
    0x52, 0x89, 0xa5, 0x1b, 0x27, 0xb0, 0x26, 0xdc, 0xca, 0x2e, 0x22, 0x30, 0xc0, 0xd8, 0x91, 0xc6,
    0x27, 0x40, 0xca, 0x17, 0x9c, 0x79, 0xac, 0x4e, 0xed, 0x43, 0x25, 0x77, 0x5b, 0x75, 0xfc, 0x43,
    0xef, 0x2f, 0x9a, 0x65, 0xbf, 0x60, 0x88, 0xdd, 0xc4, 0x24, 0x73, 0x09, 0x26, 0xfc, 0x10, 0xb8,
    0xca, 0xb3, 0x90, 0x58, 0xeb, 0xec, 0x81, 0x90, 0x0e, 0x15, 0x3e, 0xb4, 0x34, 0x77, 0x81, 0x52,
    0x04, 0x6c, 0xf0, 0x85, 0xfd, 0xcd, 0x16, 0xde, 0x88, 0x7c, 0x68, 0x07, 0x89, 0x68, 0x85, 0x1e,
    0x03, 0x97, 0x4e, 0xb1, 0xad, 0x3c, 0x48, 0x03, 0x75, 0x2b, 0x54, 0x03, 0x75, 0x1a, 0xd5, 0x07,
    0x8a, 0xc3, 0xa2, 0xa9, 0x40, 0xa1, 0x21, 0xac, 0xe5, 0xd1, 0x61, 0xba, 0x4c, 0xba, 0x2f, 0x66,
    0xb0, 0x03, 0x9e, 0xa9, 0x0c, 0x60, 0x9e, 0x15, 0xe1, 0xa0, 0x8d, 0xac, 0x34, 0xf8, 0x03, 0x08,
    0xd8, 0x1a, 0xc3, 0xcb, 0x5e, 0x91, 0xe9, 0x7a, 0x3e, 0x05, 0x1f, 0x0b, 0x42, 0x7d, 0x51, 0x56,
    0xbe, 0x46, 0x33, 0x43, 0x0c, 0x9a, 0xda, 0xe7, 0xbe, 0x50, 0x10, 0x8e, 0xc6, 0xb4, 0xd1, 0x42,
    0xbb, 0x09, 0x18, 0x65, 0x1a, 0xdc, 0x0f, 0x82, 0x30, 0x34, 0xf8, 0xe9, 0xf8, 0x59, 0xf4, 0x9f,
    0x4c, 0xba, 0x1d, 0x16, 0xbf, 0xa2, 0xb0, 0x3b, 0xc4, 0xda, 0x7d, 0x65, 0xcc, 0xaa, 0x0e, 0xe0,
    0xcd, 0x2c, 0xb6, 0x01, 0x8d, 0x80, 0xa9, 0x04, 0xa8, 0x43, 0x69, 0xa3, 0x37, 0xc1, 0xf0, 0x2f,
    0x27, 0xf0, 0x83, 0x57, 0x60, 0x17, 0x21, 0xe2, 0xe8, 0x71, 0x89, 0x83, 0x0e, 0xbb, 0x91, 0x84,
    0xb9, 0xf6, 0xc5, 0xd0, 0xd5, 0x68, 0xb2, 0xeb, 0xd9, 0x5c, 0x65, 0x37, 0xd1, 0xcb, 0xab, 0x43,
    0x4c, 0xd7, 0x55, 0x28, 0x44, 0x97, 0x7d, 0x4d, 0x7a, 0xeb, 0x47, 0x3c, 0x49, 0x53, 0x1f, 0x22,
    0x12, 0x8b, 0x83, 0xd1, 0x4f, 0x72, 0x35, 0x71, 0xf1, 0x47, 0xa9, 0xb9, 0xd4, 0x49, 0xd5, 0xe4,
    0xd2, 0xdc, 0xee, 0x90, 0x82, 0xe6, 0xe8, 0x47, 0xa9, 0xfb, 0x3c, 0x9e, 0x8d, 0xa3, 0xe6, 0x1a,
    0x19, 0x29, 0x08, 0x68, 0x85, 0x10, 0xb2, 0x3f, 0x12, 0x3b, 0x89, 0x7c, 0x78, 0x64, 0x20, 0x09,
    0x24, 0x69, 0xc4, 0xf1, 0x0b, 0x27, 0xba, 0xd0, 0x3f, 0xb9, 0x08, 0x80, 0x76, 0x10, 0x23, 0x7a,
    0xa7, 0xb6, 0xc8, 0x30, 0x27, 0xbf, 0x42, 0xcc, 0x28, 0x27, 0x37, 0x35, 0x13, 0x32, 0xcd, 0x19,
    0xdc, 0x63, 0xa2, 0x5f, 0x0a, 0xc8, 0xf1, 0x69, 0x08, 0x7e, 0x05, 0x20, 0x2d, 0xff, 0xf1, 0x70,
    0x8a, 0x41, 0xed, 0x87, 0x13, 0x7a, 0x87, 0x90, 0x2e, 0x14, 0xc6, 0x4b, 0x19, 0x40, 0xdc, 0x4f,
    0xb1, 0x13, 0x80, 0xf2, 0x90, 0xd7, 0x27, 0x11, 0x85, 0x5e, 0x16, 0x6a, 0x01, 0x6f, 0x7b, 0x5e,
    0x88, 0x91, 0x02, 0x94, 0x88, 0x32, 0x3d, 0x45, 0xd2, 0xe7, 0xbd, 0xaa, 0xff, 0xd8, 0x0e, 0x50,
    0xa4, 0xf7, 0x85, 0x18, 0xb3, 0x04, 0x0e, 0xca, 0x60, 0xe4, 0x61, 0x44, 0x2b, 0x0f, 0xa8, 0x7a,
    0x57, 0x57, 0x6c, 0x04, 0xbb, 0x95, 0x5b, 0x94, 0x21, 0xb5, 0x50, 0x14, 0x67, 0xce, 0x0d, 0xae,
    0xfd, 0xa9, 0xf8, 0x36, 0x66, 0xda, 0x04, 0x94, 0x49, 0xc3, 0x19, 0xd9, 0x86, 0xad, 0xd0, 0xd1,
    0x65, 0xc1, 0x92, 0x46, 0x1e, 0x04, 0xfe, 0xad, 0xc1, 0x68, 0x12, 0xe8, 0x79, 0x82, 0x3b, 0x2e,
    0x31, 0x14, 0x26, 0x98, 0xcf, 0x87, 0xb8, 0x08, 0xab, 0x23, 0x05, 0x6e, 0x20, 0xe0, 0x57, 0x81,
    0x81, 0x55, 0x07, 0xbf, 0x16, 0xf4, 0xb1, 0x86, 0x64, 0x45, 0x54, 0xf0, 0x15, 0xf1, 0x8e, 0x38,
    0xd8, 0xf8, 0x8e, 0x19, 0xb9, 0x86, 0x0c, 0x05, 0xb7, 0x09, 0x6e, 0x91, 0xda, 0x07, 0xbf, 0xf4,
    0x61, 0x6f, 0xdb, 0x65, 0x09, 0x92, 0xd9, 0x2e, 0x18, 0x15, 0x3a, 0x78, 0x19, 0x80, 0x25, 0x99,
    0x3d, 0x49, 0x0a, 0xe2, 0x48, 0x5d, 0xc8, 0x01, 0x33, 0xf8, 0x08, 0x54, 0x2c, 0x4c, 0x38, 0x66,
    0x69, 0x2b, 0x27, 0x19, 0xc5, 0xad, 0xaf, 0x5d, 0x5b, 0x8e, 0x3a, 0xa8, 0xb2, 0xea, 0xa1, 0xb5,
    0x5a, 0x2c, 0xba, 0xdd, 0x89, 0x6b, 0x5b, 0x10, 0xbb, 0x67, 0x20, 0x00, 0xc9, 0x73, 0x51, 0x52,
    0x00, 0x99, 0xf1, 0xb4, 0x8a, 0x97, 0x49, 0x24, 0x4b, 0xb6, 0x8b, 0x1e, 0x01, 0x35, 0xf2, 0xc2,
    0x91, 0x8b, 0x84, 0x7f, 0x8d, 0x70, 0x83, 0x3c, 0x08, 0x50, 0x3e, 0xf8, 0xd9, 0x31, 0x92, 0x35,
    0x3d, 0x3f, 0xda, 0x90, 0xf4, 0x10, 0xfd, 0x5d, 0x99, 0x7a, 0xa2, 0x67, 0x7b, 0x6f, 0x6d, 0x64,
    0xa1, 0x5c, 0x05, 0x8a, 0x57, 0x67, 0x81, 0x9e, 0xdb, 0x01, 0x73, 0x5e, 0x4f, 0x2e, 0x8f, 0xd7,
    0x90, 0xc4, 0x4d, 0xe3, 0x6d, 0x12, 0x84, 0x94, 0xc5, 0x1d, 0x59, 0x91, 0xea, 0x4a, 0x76, 0x24,
    0x80, 0x89, 0x23, 0x6d, 0x06, 0x1c, 0xcb, 0x80, 0xc2, 0x5b, 0x43, 0xa8, 0xf0, 0x09, 0x78, 0x96,
    0xfb, 0x47, 0x8f, 0x30, 0x39, 0x24, 0x63, 0xee, 0x22, 0x03, 0x68, 0x08, 0x45, 0x23, 0x8f, 0xe4,
    0xf6, 0x19, 0xd0, 0x30, 0x16, 0x1f, 0xda, 0x48, 0x79, 0xaf, 0x5a, 0x62, 0x19, 0x07, 0x1f, 0x7e,
    0x0f, 0x73, 0x3c, 0x34, 0xd9, 0x31, 0xe0, 0xca, 0xfb, 0x53, 0x09, 0x02, 0xc4, 0x9a, 0x5b, 0x88,
    0x7c, 0x63, 0x07, 0x91, 0xc5, 0x0a, 0x6f, 0x41, 0x1b, 0x20, 0x69, 0x19, 0xde, 0x1d, 0x71, 0x8b,
    0xe2, 0x0c, 0x6d, 0xb6, 0xa2, 0x3f, 0xcb, 0x79, 0x91, 0x02, 0x2c, 0xfc, 0xea, 0x70, 0x5c, 0x67,
    0x9b, 0x63, 0xc0, 0x4f, 0x0f, 0x6e, 0x14, 0x7c, 0x11, 0x90, 0x54, 0x04, 0x51, 0xbe, 0x22, 0x81,
    0x31, 0x90, 0x49, 0x9c, 0xdd, 0x1d, 0x40, 0xd0, 0x43, 0x00, 0x6b, 0xea, 0x78, 0x26, 0xd6, 0x09,
    0x83, 0x61, 0x3b, 0xc9, 0x76, 0xeb, 0xc4, 0x01, 0x08, 0x46, 0xe1, 0xfb, 0xd7, 0x7d, 0xba, 0x62,
    0xeb, 0xeb, 0xb3, 0x0a, 0x8a, 0xed, 0xe5, 0x0b, 0xaf, 0x62, 0x5e, 0x6d, 0x47, 0x11, 0xde, 0xce,
    0x93, 0x60, 0x00, 0x2e, 0x47, 0x52, 0x38, 0xd3, 0x49, 0x5c, 0x6c, 0x1b, 0xdc, 0xdd, 0x86, 0x93,
    0x38, 0x2e, 0x42, 0x0e, 0xc7, 0x32, 0x41, 0x0e, 0xbb, 0x56, 0x57, 0x11, 0x9a, 0xfb, 0x58, 0x13,
    0xa4, 0x5a, 0x9f, 0x7e, 0x42, 0x3e, 0x3e, 0x98, 0x43, 0xae, 0x4c, 0x86, 0xb0, 0xed, 0x51, 0x21,
    0x09, 0xa6, 0x08, 0x36, 0x13, 0x97, 0xaf, 0x5f, 0xd7, 0x67, 0x8d, 0xdc, 0x1a, 0x08, 0xcd, 0xf9,
    0xc0, 0xac, 0x12, 0xfa, 0x90, 0x5a, 0xef, 0x17, 0xf5, 0xb5, 0x37, 0xd7, 0xed, 0x20, 0xf4, 0x24,
    0x93, 0xa3, 0x42, 0xed, 0xad, 0x54, 0x23, 0x4b, 0x30, 0x15, 0x0f, 0x04, 0x61, 0xdd, 0xa1, 0xc6,
    0x69, 0xde, 0xfd, 0x87, 0x51, 0xd2, 0x8b, 0x23, 0x8d, 0x0c, 0xf4, 0x3b, 0x4f, 0x07, 0xc9, 0xda,
    0xd0, 0x41, 0x38, 0x88, 0xb9, 0x90, 0x4f, 0x72, 0x92, 0x44, 0x04, 0x62, 0x0f, 0x18, 0xf9, 0x89,
    0xe1, 0x06, 0xc8, 0x84, 0x50, 0xc9, 0x43, 0x5d, 0x8c, 0xac, 0x38, 0xd7, 0x90, 0x36, 0x6b, 0x91,
    0x2e, 0xcd, 0x96, 0xcd, 0x8b, 0x13, 0xd8, 0x85, 0x13, 0x99, 0x79, 0xd4, 0x0a, 0x74, 0x8f, 0xa6,
    0x26, 0x19, 0xa2, 0x20, 0xd8, 0x5d, 0xc0, 0xe4, 0xf7, 0xa3, 0x5d, 0x21, 0x22, 0xbf, 0xd3, 0x05,
    0x86, 0x60, 0xf6, 0xd5, 0x00, 0x36, 0x5e, 0x5a, 0xb9, 0xa8, 0xc7, 0xf3, 0xdc, 0xea, 0x83, 0x08,
    0x57, 0x24, 0x56, 0xf7, 0x2b, 0x40, 0x2a, 0x0d, 0x56, 0x8e, 0x31, 0x50, 0xb9, 0xd6, 0x57, 0x44,
    0x72, 0x09, 0x44, 0x79, 0xe7, 0x7f, 0xb1, 0x83, 0xa9, 0xc4, 0xbb, 0xcd, 0x20, 0x06, 0x4b, 0xae,
    0xf1, 0xe0, 0x13, 0x9a, 0x54, 0x72, 0xef, 0xbc, 0x5c, 0x24, 0x75, 0x87, 0x49, 0x1b, 0xb2, 0xc9,
    0x97, 0x0f, 0x49, 0x37, 0x71, 0x93, 0x56, 0x59, 0x34, 0x03, 0x26, 0x58, 0xc3, 0xdd, 0x98, 0x30,
    0x2d, 0x54, 0x8f, 0xdc, 0x75, 0xf6, 0xaf, 0x25, 0x04, 0xe8, 0xce, 0x70, 0x00, 0xc4, 0x45, 0x09,
    0xdc, 0x68, 0x3a, 0x65, 0x03, 0x41, 0xfd, 0x09, 0xc4, 0x3f, 0xe1, 0x31, 0x78, 0xb0, 0x0c, 0x37,
    0x10, 0xf6, 0xa7, 0x14, 0x3a, 0xe9, 0xa9, 0xcf, 0xb2, 0x5d, 0xfc, 0x9d, 0xe4, 0x1a, 0xa2, 0xff,
    0xc4, 0x65, 0x5b, 0x3c, 0xbe, 0x8f, 0x12, 0xfa, 0x13, 0x42, 0xeb, 0x82, 0x16, 0xf1, 0x12, 0xc4,
    0xcf, 0x45, 0xaa, 0xfe, 0x70, 0xd0, 0xb0, 0x14, 0xf9, 0xc8, 0xc4, 0xe7, 0x50, 0x86, 0xc8, 0x8d,
    0x31, 0x65, 0xbd, 0xa2, 0x4d, 0x1a, 0xec, 0x8c, 0x62, 0x28, 0xa2, 0x69, 0x14, 0x24, 0xb4, 0xc3,
    0x34, 0x25, 0x80, 0xc8, 0x29, 0x71, 0xdf, 0x8a, 0xe1, 0x0d, 0xe3, 0x15, 0xe6, 0xbe, 0x74, 0x1a,
    0xbb, 0x66, 0xbb, 0xa3, 0x30, 0x76, 0x22, 0x7b, 0xef, 0xdb, 0x19, 0x13, 0xb9, 0x84, 0x14, 0xa3,
    0x98, 0xb8, 0x60, 0x00, 0x2d, 0xdb, 0x04, 0x81, 0x12, 0x8f, 0xb8, 0x81, 0x48, 0x36, 0x18, 0x08,
    0x93, 0x7d, 0x04, 0x16, 0x73, 0xe3, 0xbc, 0x41, 0x7b, 0x22, 0x1b, 0x23, 0xba, 0x24, 0xe9, 0x3a,
    0x25, 0x31, 0x90, 0xaf, 0xc5, 0x80, 0xff, 0xf5, 0x84, 0xad, 0x8d, 0x67, 0x13, 0x2f, 0x9e, 0x4d,
    0x8f, 0x46, 0x07, 0x03, 0xbe, 0xb4, 0xb4, 0xe8, 0xcd, 0x23, 0x2e, 0x97, 0x7e, 0x36, 0x05, 0x7c,
    0x25, 0x5c, 0x1e, 0x72, 0xa0, 0x74, 0xfa, 0x92, 0x97, 0x66, 0x3d, 0xfb, 0x51, 0xa8, 0x9b, 0xee,
    0x2a, 0xf9, 0x6c, 0xc9, 0xa6, 0xc2, 0x03, 0x9b, 0x52, 0x05, 0x95, 0xb7, 0x29, 0xb4, 0xd1, 0xac,
    0x0b, 0x78, 0x0a, 0x30, 0xd1, 0x41, 0xee, 0x7d, 0xaa, 0x9b, 0x85, 0xad, 0x1d, 0x55, 0x05, 0xaa,
    0x38, 0x9c, 0x39, 0xe7, 0x70, 0xa8, 0xb2, 0x19, 0x5c, 0x5d, 0x16, 0x06, 0x83, 0xdd, 0xc0, 0xe8,
    0x4d, 0x2f, 0x88, 0x9f, 0xe9, 0xb0, 0x20, 0x38, 0x96, 0x96, 0x22, 0x5a, 0x5d, 0xea, 0xc6, 0x9a,
    0x3c, 0x8c, 0x71, 0x31, 0xb5, 0xf4, 0xe7, 0x48, 0x02, 0x21, 0x4a, 0x5c, 0x1c, 0x07, 0x37, 0x29,
    0xa7, 0x2a, 0xd6, 0x8e, 0x83, 0x8e, 0x16, 0x46, 0x03, 0x38, 0x8b, 0xfe, 0x03, 0xd8, 0x38, 0x9e,
    0x57, 0x59, 0x79, 0x89, 0x03, 0x7b, 0x90, 0xad, 0xff, 0x26, 0x86, 0x50, 0x0a, 0x71, 0xa9, 0x71,
    0xd6, 0xc6, 0x76, 0xf4, 0x1c, 0x7d, 0x9d, 0x73, 0xc8, 0xbe, 0x8e, 0x94, 0x61, 0x09, 0x49, 0x87,
    0x3c, 0x0b, 0x9c, 0x98, 0xb6, 0x92, 0xe3, 0x8c, 0x90, 0xe4, 0xed, 0xd3, 0x9f, 0x23, 0x12, 0x89,
    0xf6, 0x14, 0x68, 0x0e, 0xd2, 0x4f, 0x9b, 0x9c, 0x33, 0x89, 0xa2, 0x80, 0xd1, 0xdc, 0x93, 0x39,
    0x76, 0xb0, 0x7b, 0x42, 0x94, 0x32, 0x2c, 0x04, 0xfe, 0xfb, 0x2d, 0x88, 0x98, 0xfc, 0x32, 0x82,
    0x62, 0x11, 0x09, 0x11, 0x10, 0xb8, 0x63, 0x1d, 0xf7, 0xa9, 0x03, 0x6a, 0x3b, 0x97, 0x49, 0x64,
    0x13, 0xa2, 0xb7, 0xb8, 0xb4, 0x96, 0xdb, 0x68, 0xe6, 0x2e, 0xec, 0x9a, 0x18, 0xc1, 0x08, 0x98,
    0x04, 0x71, 0x18, 0x24, 0x40, 0xa3, 0x32, 0x05, 0xe6, 0x84, 0x42, 0xc3, 0xa2, 0x4c, 0x67, 0x49,
    0x14, 0x43, 0xe5, 0xe2, 0x36, 0x1f, 0x51, 0x61, 0x59, 0x88, 0x5e, 0x6f, 0xb8, 0xc6, 0xfb, 0xb6,
    0x1a, 0x75, 0xc3, 0xad, 0x25, 0x3c, 0x10, 0x90, 0xf8, 0xe8, 0x64, 0x9a, 0x7d, 0x6b, 0x5f, 0xfa,
    0x6c, 0x08, 0xa0, 0x53, 0x4e, 0x0f, 0xab, 0x81, 0x0a, 0x0e, 0x9a, 0x13, 0x2e, 0x54, 0x10, 0xd1,
    0x07, 0x02, 0xf2, 0xaf, 0xb0, 0x05, 0xf5, 0xd4, 0xd2, 0x94, 0x15, 0x17, 0x93, 0x2d, 0x4c, 0x3e,
    0x3e, 0x16, 0x61, 0x62, 0xb5, 0xb6, 0xe7, 0x3c, 0x86, 0x34, 0xaf, 0xa8, 0x0c, 0xd7, 0x8c, 0x79,
    0xc9, 0xc3, 0xad, 0xeb, 0xa8, 0x75, 0x5d, 0x03, 0x54, 0x5e, 0xc4, 0xbf, 0xba, 0x1d, 0x75, 0x05,
    0xed, 0x64, 0x4d, 0x84, 0xe7, 0xe1, 0x3f, 0x6a, 0x61, 0xd5, 0xe2, 0x90, 0xe7, 0xf3, 0xff, 0xe7,
    0xba, 0xee, 0x5f, 0x94, 0x2a, 0x17, 0x36, 0xec, 0x13, 0x5d, 0xea, 0x7e, 0x86, 0xb5, 0x47, 0x13,
    0xf6, 0x31, 0x70, 0xbc, 0x13, 0xe4, 0xcd, 0x2e, 0x50, 0xb6, 0x32, 0xf0, 0x1c, 0xdd, 0xc1, 0xac,
    0xd8, 0xd8, 0xe9, 0xd4, 0x44, 0xb0, 0x3e, 0x62, 0x69, 0x46, 0x0a, 0x5f, 0xa4, 0xb8, 0x01, 0x5b,
    0x03, 0xdc, 0xc1, 0xb3, 0xf1, 0x27, 0x0e, 0xbc, 0x21, 0xae, 0x3d, 0x7a, 0xce, 0xb3, 0x40, 0x61,
    0xb2, 0xe4, 0xc2, 0x13, 0x11, 0xfb, 0x9c, 0x29, 0x21, 0x5e, 0x41, 0xdb, 0x8e, 0x20, 0xdb, 0x87,
    0x70, 0x88, 0x25, 0xa5, 0x52, 0x08, 0xeb, 0x21, 0x06, 0x85, 0x4b, 0xbb, 0x0c, 0x37, 0x18, 0x94,
    0xb8, 0x72, 0xb8, 0x11, 0xdc, 0x8c, 0x08, 0x85, 0x61, 0x8c, 0xd0, 0x26, 0x18, 0x86, 0x50, 0xba,
    0x03, 0xc6, 0xbb, 0x0b, 0x88, 0x93, 0x43, 0x32, 0x53, 0x42, 0x89, 0x92, 0x50, 0x6e, 0xd1, 0xb1,
    0xa0, 0x95, 0xdc, 0xf8, 0x46, 0x35, 0xdc, 0xd2, 0x8d, 0x5c, 0x01, 0x56, 0x84, 0x22, 0xe1, 0x49,
    0x24, 0x70, 0x75, 0xc2, 0xbf, 0xa8, 0x7a, 0xa0, 0xe3, 0x09, 0x2e, 0x15, 0x7e, 0x90, 0x84, 0xba,
    0xe7, 0xdc, 0x85, 0xc4, 0x01, 0x8b, 0xef, 0x0a, 0x71, 0xea, 0x38, 0x01, 0x1d, 0x63, 0x6b, 0xb1,
    0x22, 0x57, 0xa4, 0x75, 0x10, 0x85, 0xda, 0x77, 0xbd, 0x30, 0x24, 0xf4, 0x62, 0xe1, 0x15, 0x56,
    0xf4, 0x96, 0x86, 0xb4, 0x8b, 0x88, 0xc6, 0x87, 0xee, 0xc9, 0x89, 0x61, 0x69, 0xb9, 0x27, 0xa1,
    0xf3, 0x6a, 0x0c, 0x91, 0xf9, 0xf8, 0x78, 0x91, 0x82, 0xa0, 0x50, 0x9b, 0x97, 0x84, 0xdd, 0xc3,
    0x10, 0xc1, 0x3e, 0xf6, 0xf1, 0x9c, 0x64, 0x21, 0x00, 0xa6, 0x43, 0xc6, 0xe2, 0x05, 0xfe, 0xfc,
    0x4b, 0x63, 0x18, 0xe2, 0x02, 0x2d, 0x94, 0x24, 0x35, 0x77, 0xc0, 0x89, 0x0a, 0x53, 0x85, 0x9b,
    0x6e, 0xbf, 0x7b, 0xd1, 0xeb, 0x15, 0xd3, 0x91, 0x31, 0xb1, 0xa2, 0x44, 0x65, 0x08, 0x3f, 0x32,
    0xb3, 0xc1, 0xd6, 0x0a, 0x0d, 0x9f, 0x58, 0xec, 0xc4, 0xcd, 0x6c, 0x4d, 0x3d, 0x67, 0x13, 0x88,
    0x1d, 0x79, 0x4a, 0x21, 0xa2, 0x69, 0xc9, 0x93, 0x2f, 0x2c, 0x27, 0xf7, 0x1d, 0x0d, 0x52, 0x68,
    0x98, 0x98, 0xda, 0x66, 0x9a, 0x03, 0x2d, 0x9d, 0x6e, 0x0b, 0x7e, 0x0c, 0x29, 0x88, 0x67, 0x62,
    0x77, 0x0c, 0xcd, 0x26, 0x87, 0xa3, 0x39, 0xca, 0x7e, 0xc7, 0x0c, 0x06, 0x3b, 0x6b, 0x10, 0x07,
    0x9c, 0x97, 0x26, 0xf4, 0x72, 0x12, 0xcd, 0xc8, 0x8c, 0x76, 0x1b, 0x4c, 0x76, 0x73, 0xc0, 0x4b,
    0xc7, 0xa6, 0x10, 0x1f, 0x16, 0x17, 0x5a, 0x5e, 0xd9, 0x8c, 0xdd, 0x14, 0x33, 0x30, 0xa1, 0x15,
    0x86, 0x1b, 0x73, 0x7e, 0x9b, 0xf9, 0x28, 0x1f, 0x42, 0xc0, 0x56, 0x46, 0x18, 0x4a, 0x8c, 0xaf,
    0x2b, 0x98, 0x51, 0xf6, 0xa2, 0xeb, 0xca, 0x4f, 0xa2, 0x25, 0x52, 0xeb, 0xeb, 0xc3, 0x10, 0x38,
    0x29, 0xaf, 0x1b, 0xd1, 0xda, 0x73, 0xe9, 0x16, 0x83, 0xba, 0x69, 0x45, 0xf5, 0xd5, 0xd9, 0xa6,
    0x5f, 0x53, 0xa6, 0x54, 0x75, 0x36, 0x2c, 0xba, 0xbc, 0xbc, 0x2b, 0x95, 0x8a, 0x1a, 0x6e, 0x78,
    0x70, 0xda, 0xf6, 0x23, 0x82, 0xc3, 0xb7, 0x5e, 0x06, 0x7d, 0x88, 0x24, 0x66, 0xe8, 0x69, 0x92,
    0x87, 0xf1, 0x31, 0xb4, 0x83, 0x8c, 0xf3, 0x5f, 0x25, 0x0e, 0xff, 0x94, 0x14, 0x50, 0x8f, 0x0d,
    0xc1, 0xe1, 0x4f, 0x25, 0x7b, 0x2d, 0xf0, 0xdb, 0x56, 0xe2, 0x10, 0xc8, 0x10, 0xa3, 0x64, 0x33,
    0xb8, 0xd1, 0x42, 0x7f, 0xc2, 0x54, 0xe3, 0x38, 0x4d, 0x14, 0xb0, 0x80, 0x9c, 0xa8, 0x15, 0x79,
    0x4c, 0xdc, 0xf3, 0x4e, 0x26, 0x2b, 0x37, 0x17, 0x17, 0xf1, 0x9b, 0x87, 0x3a, 0xcf, 0x4e, 0xc9,
    0x50, 0x67, 0xb1, 0x9b, 0x23, 0x88, 0x29, 0x3d, 0x5d, 0xcc, 0xd9, 0x2b, 0xa9, 0xad, 0x08, 0xdb,
    0x05, 0x25, 0xf7, 0x73, 0x19, 0xcb, 0xdd, 0xe3, 0x65, 0xfd, 0x40, 0xed, 0x30, 0xb6, 0x01, 0x7b,
    0x82, 0x19, 0xbe, 0x39, 0x86, 0x8a, 0xa0, 0x05, 0xd0, 0x4a, 0x1e, 0xdf, 0x08, 0xa6, 0xe2, 0x62,
    0x8f, 0xb2, 0xd1, 0x89, 0x08, 0xe0, 0xbe, 0x36, 0x90, 0x86, 0x89, 0x20, 0xa2, 0x13, 0x37, 0xe7,
    0x78, 0x61, 0x05, 0x03, 0xba, 0xeb, 0xda, 0x90, 0x7c, 0x70, 0x4c, 0x47, 0x1e, 0x8d, 0x24, 0x21,
    0x37, 0x39, 0x9a, 0x26, 0x4b, 0x61, 0xcc, 0x4d, 0x31, 0x93, 0x0b, 0x81, 0x7b, 0x1a, 0x59, 0x26,
    0x5a, 0x63, 0x13, 0xf0, 0x32, 0xe3, 0x80, 0x11, 0x24, 0x85, 0x74, 0xc5, 0x21, 0x00, 0x32, 0x23,
    0xf3, 0xf2, 0x62, 0x8c, 0xa8, 0xea, 0xfd, 0xd9, 0x3e, 0xfd, 0x3d, 0x6f, 0x15, 0xe8, 0xa9, 0x27,
    0x3d, 0x89, 0x0d, 0x1d, 0x28, 0x28, 0x6a, 0x23, 0x8f, 0x18, 0xb0, 0x96, 0xcb, 0xd6, 0x24, 0xce,
    0x0e, 0x5f, 0x12, 0x8f, 0xe0, 0x86, 0x87, 0xdd, 0xc3, 0x14, 0x69, 0x44, 0xb2, 0x3f, 0x8b, 0xb2,
    0x7b, 0x85, 0x1b, 0xdc, 0x82, 0x98, 0xce, 0x90, 0x91, 0xdd, 0x64, 0xd5, 0x3b, 0x48, 0xfb, 0xb3,
    0xfe, 0xf4, 0x66, 0x3e, 0x0b, 0x26, 0xc4, 0xe7, 0x20, 0x5f, 0x70, 0xa7, 0x3f, 0xf4, 0x19, 0xfb,
    0x8e, 0xa9, 0x5f, 0xc1, 0x16, 0x62, 0x3c, 0x28, 0x10, 0x20, 0x81, 0x45, 0x1e, 0x05, 0xde, 0xa6,
    0x48, 0x94, 0xe3, 0x25, 0x5d, 0x7f, 0x72, 0x15, 0x0d, 0x62, 0x51, 0x68, 0xc6, 0x21, 0x93, 0x8f,
    0xb9, 0x7d, 0x8b, 0x8d, 0x21, 0x91, 0x28, 0xd6, 0x98, 0x79, 0xa1, 0xc5, 0x88, 0x86, 0x42, 0x9c,
    0x11, 0xc1, 0xb6, 0x40, 0xe2, 0x11, 0xd6, 0x22, 0x4e, 0x80, 0x09, 0xee, 0x0b, 0xd8, 0xd6, 0x60,
    0x88, 0x48, 0xdd, 0x24, 0x70, 0x18, 0x57, 0xf4, 0x33, 0xa8, 0x1e, 0xa6, 0xd0, 0xd8, 0xd8, 0x58,
    0x6d, 0xa3, 0x4b, 0xac, 0x4a, 0x88, 0x41, 0x45, 0x51, 0x0c, 0x8f, 0x1c, 0x22, 0x1f, 0xea, 0xed,
    0x56, 0x2b, 0x6a, 0x06, 0x35, 0x10, 0xda, 0xb1, 0x09, 0x3e, 0xc8, 0x31, 0xc9, 0xa6, 0x1f, 0xc2,
    0x44, 0x34, 0x7a, 0xe1, 0x34, 0xe8, 0x17, 0x3e, 0x11, 0xf4, 0x1f, 0xd9, 0x38, 0xc1, 0xc7, 0x2a,
    0x68, 0xc4, 0x2e, 0x61, 0x04, 0xf3, 0xa0, 0x4d, 0x3d, 0x7d, 0x70, 0x3b, 0x98, 0x91, 0x72, 0xa3,
    0x51, 0x49, 0xf1, 0x31, 0xd0, 0x9a, 0xc4, 0x8e, 0xcb, 0x90, 0xc6, 0x00, 0xa8, 0xaf, 0xc8, 0x90,
    0x37, 0xfa, 0x0a, 0x94, 0xe6, 0x1a, 0x77, 0x5f, 0x52, 0x0d, 0x2e, 0xab, 0x8e, 0x6b, 0xaf, 0xa6,
    0x08, 0x4a, 0xfb, 0xe4, 0x2e, 0xd3, 0x4d, 0x0c, 0x91, 0xf9, 0x49, 0x25, 0x16, 0xc6, 0x97, 0x09,
    0xf1, 0x88, 0xd9, 0x9d, 0xc1, 0x88, 0xd9, 0x92, 0x39, 0xbd, 0xc5, 0xba, 0xe3, 0x49, 0xd0, 0x78,
    0x50, 0x20, 0x65, 0xb6, 0x3f, 0xc0, 0x31, 0xc6, 0xb1, 0x49, 0x1e, 0x28, 0xfd, 0x9a, 0x71, 0xb1,
    0x0c, 0x8b, 0xae, 0x7f, 0xc3, 0xb7, 0x21, 0xb4, 0x19, 0x8e, 0xe6, 0x2a, 0x16, 0xc2, 0x9f, 0xd9,
    0x82, 0x23, 0x34, 0x14, 0x60, 0xe8, 0xb6, 0x65, 0x66, 0x24, 0xbb, 0xf3, 0x13, 0x52, 0x1b, 0x07,
    0x83, 0xd8, 0x4e, 0x9d, 0x83, 0xf6, 0x36, 0x31, 0x36, 0x31, 0xa1, 0x88, 0xb3, 0x78, 0x3c, 0x80,
    0x19, 0xab, 0x51, 0x5e, 0xac, 0x9e, 0x34, 0x64, 0xb4, 0x0f, 0x8b, 0xde, 0x7a, 0x22, 0x01, 0x5b,
    0x6c, 0xdb, 0x09, 0x89, 0x06, 0x62, 0xb9, 0x77, 0x9e, 0x8c, 0x40, 0x8a, 0x80, 0x06, 0x0e, 0xd7,
    0x4d, 0xab, 0x98, 0x8b, 0xe7, 0x01, 0xee, 0x93, 0x4c, 0xb2, 0x61, 0xf1, 0xfb, 0x71, 0xc6, 0xbf,
    0xdf, 0x0b, 0x57, 0xfb, 0x87, 0xc4, 0xc7, 0x68, 0x20, 0x38, 0x67, 0x07, 0x0d, 0x07, 0x0b, 0x08,
    0x8b, 0xba, 0x1e, 0xec, 0x5b, 0x78, 0x2a, 0x49, 0x0f, 0x0e, 0x90, 0x42, 0xe1, 0xdf, 0x27, 0x02,
    0x98, 0x8e, 0x1c, 0x7a, 0x71, 0x31, 0x8a, 0x4e, 0x21, 0x09, 0xe4, 0x7e, 0x88, 0xe3, 0x4b, 0xf6,
    0xb5, 0x7b, 0x40, 0xa9, 0x14, 0x33, 0xad, 0x34, 0x92, 0x43, 0x3b, 0x08, 0xc8, 0x5f, 0xa0, 0xef,
    0xc5, 0x89, 0x18, 0x79, 0x62, 0x3a, 0xa0, 0x79, 0xeb, 0x37, 0x8c, 0x86, 0xcd, 0xa2, 0xbc, 0x0c,
    0x90, 0x9a, 0x04, 0x6c, 0x88, 0xce, 0xf6, 0x0d, 0x8d, 0x08, 0x43, 0x99, 0x61, 0xb3, 0x23, 0x28,
    0x82, 0xdf, 0x8d, 0xa5, 0xa3, 0x89, 0x2b, 0x86, 0x21, 0x07, 0x0a, 0xf1, 0x8d, 0x76, 0x06, 0x83,
    0x60, 0x40, 0xff, 0xec, 0x40, 0xab, 0x22, 0xec, 0x39, 0xd3, 0x71, 0x2e, 0x0f, 0x0c, 0xcf, 0x29,
    0x7a, 0xec, 0xfa, 0x45, 0xed, 0xc8, 0x3a, 0xf4, 0x42, 0x47, 0x1c, 0xc0, 0xdd, 0xb0, 0x42, 0x2c,
    0xa7, 0x12, 0x37, 0x8d, 0x08, 0x80, 0x22, 0x97, 0x54, 0xce, 0x5e, 0x65, 0x6d, 0xe6, 0x0d, 0x26,
    0x1b, 0xfc, 0x0a, 0x5f, 0x53, 0xac, 0x61, 0x2d, 0x1b, 0x3e, 0x5f, 0xd4, 0xca, 0x8f, 0x01, 0x30,
    0x7c, 0x04, 0x68, 0xb8, 0x0c, 0x87, 0x57, 0x84, 0x36, 0x0d, 0x81, 0x8c, 0x1d, 0x8d, 0x35, 0x28,
    0xde, 0x50, 0x59, 0x47, 0xb7, 0x6e, 0xe1, 0x29, 0x60, 0x01, 0x9a, 0x5c, 0x0a, 0xa2, 0x5a, 0x22,
    0x62, 0x06, 0xa3, 0x74, 0x15, 0x2a, 0x16, 0xf6, 0xe9, 0x5a, 0x56, 0xbc, 0x27, 0x27, 0xb8, 0x1b,
    0x9c, 0xcb, 0x6e, 0x7f, 0x70, 0xbc, 0x72, 0x13, 0xfe, 0x9e, 0x9e, 0x89, 0x1d, 0xdd, 0x21, 0x51,
    0xdb, 0x71, 0xce, 0xf3, 0x68, 0xe9, 0xb0, 0x83, 0xd0, 0x2d, 0x90, 0x54, 0x2e, 0x91, 0x19, 0x47,
    0xcb, 0x86, 0x89, 0xa7, 0x3d, 0x98, 0x2e, 0xb4, 0x28, 0xbd, 0x33, 0xfe, 0x6e, 0x0a, 0x56, 0x2c,
    0x5e, 0x17, 0xc1, 0x17, 0x62, 0x17, 0x1d, 0x67, 0xeb, 0x9d, 0xa9, 0x74, 0x9d, 0x8d, 0xbc, 0xa4,
    0x6e, 0x6b, 0xbe, 0xfc, 0x6a, 0x8b, 0xdf, 0x2b, 0x00, 0xe5, 0x51, 0x5e, 0xd0, 0x56, 0x68, 0xe6,
    0xe7, 0x40, 0xfc, 0x6b, 0x51, 0xf7, 0xc7, 0xaa, 0x26, 0x5f, 0xe2, 0x6a, 0xe6, 0xf1, 0x0c, 0x47,
    0x48, 0x9c, 0x75, 0x10, 0xac, 0x2b, 0x08, 0xa2, 0x95, 0x99, 0xfc, 0x0d, 0x78, 0xd6, 0xfd, 0x02,
    0x45, 0x19, 0x0b, 0x47, 0x78, 0x8e, 0xa4, 0x3b, 0x85, 0x7f, 0x0e, 0xec, 0x62, 0x8c, 0x49, 0xca,
    0x4d, 0x70, 0x09, 0xb4, 0x98, 0x87, 0xac, 0x48, 0xe8, 0xa7, 0x06, 0x36, 0x8a, 0x1f, 0x49, 0x0d,
    0x71, 0x79, 0x93, 0xae, 0x12, 0x91, 0x15, 0xe9, 0xda, 0x44, 0xad, 0x38, 0x10, 0x4d, 0xa3, 0xf0,
    0xc2, 0xfd, 0xd0, 0xf8, 0x9c, 0x41, 0x4e, 0x2e, 0x28, 0x4e, 0xff, 0xaf, 0x35, 0x0c, 0x10, 0x82,
    0x01, 0x57, 0x08, 0x92, 0x75, 0x8c, 0x77, 0x12, 0x3b, 0x88, 0x64, 0x34, 0x4d, 0x0a, 0x0a, 0x84,
    0x40, 0xc6, 0xf8, 0x1d, 0xc4, 0x48, 0x65, 0xe4, 0x11, 0x5c, 0x3a, 0xce, 0x0c, 0x6f, 0xe6, 0x14,
    0x25, 0x5a, 0x5c, 0x00, 0xaf, 0x12, 0x87, 0x5b, 0x89, 0x48, 0xfa, 0x42, 0x12, 0xe0, 0x33, 0xeb,
    0x9e, 0x80, 0x91, 0x58, 0x25, 0x40, 0xb1, 0x1c, 0xef, 0xa3, 0x22, 0x83, 0x11, 0x70, 0xdd, 0xe7,
    0x04, 0xda, 0xeb, 0x94, 0x52, 0x90, 0xcd, 0xc8, 0x13, 0x01, 0x2e, 0xdb, 0x13, 0x15, 0xe7, 0xab,
    0x5c, 0x25, 0xdc, 0x89, 0x56, 0x31, 0x21, 0x02, 0xf7, 0x24, 0xd6, 0xd2, 0xf8, 0xc3, 0x08, 0x25,
    0x76, 0x71, 0x20, 0xdd, 0x42, 0x84, 0x72, 0xaa, 0x71, 0x63, 0x4b, 0x31, 0xe7, 0xfe, 0x83, 0x44,
    0xf5, 0x0b, 0x19, 0x1a, 0x71, 0x0d, 0x86, 0x8c, 0x40, 0x63, 0x66, 0x45, 0xe4, 0x4a, 0x19, 0x96,
    0x36, 0x22, 0x18, 0x12, 0x12, 0x45, 0x01, 0xc6, 0xb1, 0x67, 0x89, 0x8d, 0x04, 0xa5, 0x25, 0x37,
    0x11, 0xe2, 0x86, 0x30, 0xdd, 0x44, 0xdc, 0x35, 0xcd, 0xf7, 0x3e, 0xc8, 0xfc, 0x1d, 0xdc, 0x26,
    0xe1, 0xb4, 0xaf, 0x0c, 0x29, 0x20, 0xe2, 0xd7, 0xa5, 0x58, 0x45, 0x87, 0x3d, 0x32, 0x82, 0x66,
    0x4f, 0x4c, 0x2a, 0x90, 0x17, 0x2d, 0x41, 0x3b, 0x84, 0x07, 0x18, 0xed, 0x8b, 0xb0, 0x17, 0xd0,
    0x4d, 0x43, 0x84, 0x56, 0x8f, 0x56, 0x61, 0x02, 0x3b, 0x39, 0xb8, 0x74, 0x0e, 0x4b, 0x75, 0x0d,
    0x9d, 0x07, 0xb4, 0x15, 0x54, 0xc7, 0x9c, 0x50, 0x64, 0xb8, 0x80, 0xf3, 0x4b, 0xc8, 0xcf, 0x86,
    0xa9, 0x1b, 0x84, 0x06, 0xd4, 0xe8, 0xb5, 0x06, 0x03, 0x21, 0x98, 0xd8, 0xca, 0xfa, 0x2e, 0xa0,
    0x18, 0xbc, 0xe7, 0x2d, 0xf3, 0x2b, 0xf4, 0x0b, 0xae, 0x2f, 0x07, 0x9a, 0x59, 0x0e, 0x3e, 0x1b,
    0x33, 0xe2, 0xec, 0x7b, 0xdd, 0x99, 0xf8, 0x99, 0x77, 0x31, 0x43, 0xc5, 0x05, 0x1d, 0x22, 0x35,
    0xdb, 0x66, 0xd4, 0x9f, 0x14, 0x98, 0x18, 0xa0, 0x20, 0x40, 0x34, 0x41, 0x57, 0x1f, 0x89, 0x96,
    0xe3, 0x5f, 0x31, 0xcc, 0x41, 0x27, 0xa7, 0x11, 0x23, 0xd0, 0xe5, 0x97, 0x0d, 0x2e, 0x3c, 0xa9,
    0x4f, 0x90, 0x0c, 0xf1, 0xf1, 0x95, 0x2e, 0x26, 0x0e, 0xa1, 0x3c, 0x63, 0xed, 0xba, 0x55, 0x67,
    0xa2, 0x71, 0x85, 0x74, 0x44, 0x97, 0x86, 0xfd, 0xe5, 0x64, 0xe6, 0xd6, 0x7f, 0xed, 0xad, 0xe3,
    0x42, 0x5c, 0xef, 0xe7, 0xbf, 0xba, 0x4c, 0xdc, 0x92, 0x2a, 0xb3, 0x4d, 0x4d, 0xff, 0xef, 0xe3,
    0x79, 0x85, 0x0b, 0x2e, 0x67, 0x06, 0xc6, 0x4a, 0x21, 0xb1, 0x12, 0x83, 0x8b, 0x9e, 0xb4, 0x3a,
    0x10, 0x16, 0x31, 0xde, 0x31, 0x6b, 0x5c, 0x63, 0xc7, 0x78, 0xbb, 0x2e, 0xe7, 0x55, 0x7f, 0xe2,
    0x4b, 0x2c, 0x25, 0xff, 0x67, 0xba, 0x17, 0x1e, 0x9c, 0xe1, 0x08, 0x6f, 0x10, 0x6f, 0xa6, 0xfe,
    0x99, 0x3d, 0x16, 0xff, 0xf7, 0x7f, 0x96, 0x47, 0xb1, 0x91, 0xae, 0xf5, 0xdc, 0x82, 0x19, 0x2e,
    0xee, 0x05, 0x2e, 0xa4, 0xed, 0x2d, 0x21, 0xa1, 0x85, 0x7d, 0xc8, 0x99, 0xa1, 0xa2, 0x55, 0x4e,
    0xa8, 0xed, 0x10, 0x81, 0x7e, 0x26, 0x4a, 0x68, 0x93, 0xb8, 0x32, 0x7c, 0x0b, 0x12, 0xf0, 0x71,
    0xa2, 0x26, 0xfe, 0xd4, 0x65, 0x01, 0x79, 0x92, 0x98, 0xcd, 0xcf, 0x8c, 0x7c, 0x38, 0x81, 0x1e,
    0x3c, 0xdf, 0x37, 0x1b, 0x42, 0x12, 0x4b, 0x75, 0xa4, 0x97, 0x72, 0x7f, 0x7b, 0x0c, 0x5d, 0xea,
    0xa8, 0x91, 0xc6, 0x3f, 0xf5, 0x91, 0xa8, 0x3b, 0xb9, 0x00, 0x27, 0x2c, 0x2c, 0x85, 0xa4, 0x91,
    0x97, 0xe1, 0x4b, 0xcd, 0x24, 0x42, 0x21, 0x3d, 0x16, 0x0a, 0x3a, 0x16, 0xd2, 0x9d, 0xcc, 0x83,
    0xf7, 0x90, 0x63, 0x16, 0xad, 0xcc, 0xd7, 0xe4, 0x3c, 0xdd, 0x28, 0x58, 0x23, 0x59, 0x64, 0xb1,
    0x9c, 0xf2, 0x9e, 0xcf, 0x57, 0x40, 0x12, 0x19, 0xc0, 0x38, 0x1e, 0xb0, 0xe6, 0x39, 0xf0, 0x64,
    0x19, 0x4c, 0x63, 0x27, 0x74, 0xa6, 0x32, 0x84, 0xdb, 0x88, 0xb6, 0x65, 0x33, 0x21, 0x2e, 0x83,
    0x58, 0x9d, 0xe8, 0x7d, 0xd9, 0xc1, 0xdf, 0x3b, 0x10, 0xa3, 0x7d, 0x73, 0xd1, 0x39, 0xf3, 0xd7,
    0x62, 0xdd, 0xdd, 0xd1, 0x91, 0x10, 0xdd, 0xd9, 0x97, 0xb1, 0x06, 0xeb, 0xcf, 0x47, 0x7f, 0x3f,
    0xc0, 0x44, 0x09, 0x76, 0x4a, 0xe0, 0x9d, 0x79, 0xba, 0x50, 0x65, 0xde, 0xec, 0xe2, 0x25, 0xa0,
    0xde, 0x2c, 0x89, 0xc6, 0x25, 0x59, 0xd8, 0xbe, 0xb4, 0xa1, 0x89, 0x14, 0xf7, 0xd7, 0x84, 0x8b,
    0x3b, 0xf2, 0xe2, 0x49, 0x28, 0x8a, 0x43, 0x48, 0x16, 0x2d, 0x0c, 0xfa, 0xe0, 0x44, 0x8f, 0x5a,
    0xba, 0xd0, 0x9b, 0x80, 0x98, 0xaf, 0xd6, 0xae, 0x10, 0x56, 0x68, 0x3f, 0x74, 0xb3, 0xc7, 0x05,
    0xd8, 0x97, 0x66, 0x3e, 0x2f, 0xf6, 0xee, 0xa2, 0x2d, 0x06, 0x8e, 0xd9, 0x22, 0x4d, 0x3f, 0xec,
    0xf8, 0x13, 0x1c, 0x4d, 0x1e, 0x64, 0x26, 0xd8, 0xd6, 0x32, 0x22, 0x10, 0xcd, 0x2f, 0x11, 0x00,
    0x29, 0x60, 0x42, 0x9d, 0xc1, 0x03, 0xc6, 0x15, 0x89, 0x89, 0xf7, 0x20, 0x66, 0xd9, 0xcc, 0x09,
    0x8d, 0xbe, 0xdd, 0xc8, 0xb3, 0xef, 0xbe, 0xee, 0x0f, 0x13, 0x64, 0x0b, 0xd6, 0x82, 0x8a, 0x72,
    0xf2, 0x74, 0x48, 0x82, 0x39, 0xa4, 0x84, 0x34, 0x6a, 0x21, 0x6a, 0x68, 0x57, 0xb2, 0x41, 0xcc,
    0x64, 0x85, 0x1c, 0x81, 0xed, 0x94, 0x57, 0x63, 0x5e, 0x53, 0x24, 0x37, 0x67, 0xf4, 0x27, 0x0d,
    0x71, 0xdb, 0xee, 0xa1, 0x86, 0x26, 0xb0, 0xbf, 0x8b, 0x88, 0xf5, 0x8e, 0x21, 0x24, 0x49, 0xaf,
    0x2c, 0x4e, 0x0d, 0x10, 0xee, 0x85, 0x93, 0xde, 0xf5, 0xfa, 0xca, 0x31, 0xef, 0x65, 0xcd, 0x9f,
    0xc8, 0xcd, 0x06, 0x26, 0xf8, 0xa1, 0x68, 0x12, 0x26, 0xf3, 0x5c, 0x4c, 0xc2, 0xaa, 0x4e, 0x2f,
    0x7f, 0x25, 0x4c, 0x98, 0x17, 0x0e, 0xe6, 0x11, 0x8e, 0x30, 0x97, 0x56, 0x77, 0x6e, 0x14, 0x18,
    0xcc, 0x40, 0x90, 0x59, 0x0d, 0x12, 0x33, 0xf4, 0x3a, 0x5d, 0x9f, 0x50, 0x5e, 0xbf, 0x84, 0xa0,
    0xa7, 0x35, 0x71, 0x28, 0xb8, 0x83, 0xad, 0x2b, 0x67, 0x10, 0x87, 0x25, 0xca, 0x7f, 0x4c, 0xf3,
    0x15, 0xe3, 0xec, 0x7e, 0x38, 0x5a, 0xfa, 0xb7, 0xe8, 0xa4, 0x6d, 0x89, 0x48, 0x7f, 0x00, 0x18,
    0x64, 0x48, 0xb8, 0x41, 0xe4, 0x6f, 0xe7, 0xc2, 0x84, 0x7e, 0xce, 0x50, 0x6d, 0x85, 0x63, 0x05,
    0xfa, 0x86, 0x05, 0xc0, 0xc8, 0x05, 0x65, 0xb6, 0x2c, 0xcb, 0xc4, 0x39, 0xd2, 0x09, 0x94, 0xe9,
    0x3a, 0xe7, 0xc5, 0xeb, 0x11, 0x24, 0x42, 0x85, 0x0e, 0x6b, 0xa6, 0xa6, 0x08, 0xcd, 0x77, 0xbb,
    0x34, 0x89, 0x1c, 0x4b, 0xa0, 0xd0, 0x03, 0xf8, 0x08, 0x79, 0xf1, 0xf9, 0x1d, 0x8d, 0x30, 0x50,
    0x70, 0x02, 0x30, 0x36, 0xc1, 0x02, 0x7d, 0x36, 0x40, 0x8e, 0x85, 0x55, 0x4e, 0xb9, 0x47, 0x39,
    0x13, 0x13, 0x19, 0x43, 0x0c, 0x10, 0xf8, 0xd0, 0xca, 0x0c, 0xea, 0xc2, 0x33, 0x10, 0x65, 0x07,
    0xf0, 0x49, 0x10, 0xb1, 0x3b, 0x52, 0x7d, 0xd2, 0x71, 0x0f, 0xb8, 0xc5, 0xdc, 0xe2, 0x3f, 0x14,
    0x61, 0xfb, 0x2c, 0x4c, 0x7a, 0x4b, 0x14, 0xe0, 0x99, 0xc7, 0xde, 0xee, 0x75, 0x3b, 0xe9, 0x96,
    0x06, 0x5f, 0xc1, 0x88, 0xa0, 0x5c, 0x13, 0x45, 0x28, 0x94, 0x49, 0x03, 0x62, 0x0c, 0x18, 0x86,
    0x74, 0xd9, 0x95, 0x4a, 0xd0, 0xdc, 0xe3, 0x48, 0xb4, 0x08, 0xd8, 0x86, 0xcf, 0x42, 0x63, 0x07,
    0x09, 0x35, 0x73, 0x68, 0x55, 0x19, 0x9a, 0xfc, 0x34, 0x42, 0xe5, 0x1f, 0x0b, 0x59, 0xae, 0x49,
    0xae, 0x38, 0xf1, 0x75, 0x59, 0x05, 0xc4, 0xbe, 0x70, 0x08, 0xb1, 0x53, 0x15, 0xc4, 0x15, 0x1a,
    0x36, 0xba, 0xa8, 0x49, 0x9a, 0xd0, 0xaf, 0xa4, 0x01, 0x61, 0x3e, 0x78, 0x65, 0xd1, 0x99, 0x00,
    0xb7, 0x14, 0xef, 0xdf, 0x6c, 0x24, 0x30, 0x98, 0x6c, 0xd3, 0x36, 0x0d, 0x53, 0xcf, 0xfc, 0xdf,
    0x18, 0x2c, 0xe1, 0xc7, 0xd2, 0x09, 0x1c, 0x60, 0x33, 0x66, 0x40, 0x53, 0xec, 0xe1, 0xb0, 0xc0,
    0xc1, 0xae, 0x65, 0xbd, 0x20, 0x9e, 0x88, 0x38, 0xda, 0xd6, 0x26, 0xf8, 0x4c, 0x92, 0x3b, 0xe8,
    0xc5, 0xc2, 0xca, 0x0d, 0xdb, 0x48, 0xf1, 0xac, 0x44, 0x62, 0xcc, 0x56, 0xa8, 0x33, 0x80, 0x88,
    0x98, 0x87, 0xde, 0x34, 0xe2, 0x7d, 0x99, 0x22, 0x15, 0xd2, 0xb1, 0x8b, 0x0b, 0xea, 0x4b, 0xcd,
    0x89, 0xde, 0xce, 0x08, 0x1e, 0x2e, 0x32, 0x04, 0x24, 0xe1, 0xb5, 0x96, 0x18, 0x89, 0x88, 0x9f,
    0x2e, 0x1a, 0x8f, 0x09, 0xe2, 0x64, 0x93, 0xc4, 0x34, 0x29, 0x45, 0xd9, 0x3e, 0xbf, 0x01, 0x25,
    0xe4, 0x24, 0x43, 0x43, 0x16, 0x45, 0xbd, 0xc4, 0x84, 0x34, 0xdd, 0xe8, 0x7d, 0xd0, 0xd0, 0xe5,
    0x37, 0x25, 0xfc, 0xb3, 0x1d, 0xe3, 0x73, 0x10, 0x61, 0xe1, 0x31, 0xcb, 0x3a, 0x54, 0x00, 0x53,
    0x1f, 0xb1, 0x36, 0x42, 0x16, 0x7c, 0xf7, 0x69, 0x1b, 0xbe, 0xbf, 0x18, 0x00, 0x98, 0x05, 0xd9,
    0x80, 0x40, 0x7f, 0x58, 0x39, 0xd6, 0x40, 0xf4, 0x78, 0x90, 0x34, 0xae, 0x80, 0x0b, 0x91, 0x41,
    0xa9, 0xac, 0x03, 0xdf, 0xc7, 0x03, 0x09, 0x89, 0xde, 0xb5, 0x4a, 0x66, 0x6c, 0x1c, 0x9a, 0x7b,
    0xe1, 0x1f, 0x28, 0xbe, 0xdf, 0x09, 0x00, 0x2e, 0x09, 0xe0, 0xfc, 0xd2, 0x0c, 0xe4, 0x00, 0x4b,
    0xe2, 0x12, 0xe0, 0xa1, 0x10, 0x05, 0xc8, 0xde, 0x09, 0xab, 0x3c, 0x39, 0x3d, 0x42, 0xfe, 0x4c,
    0x76, 0x02, 0xb1, 0xd4, 0x82, 0x20, 0x03, 0x0c, 0x5e, 0x04, 0x0e, 0x0b, 0x0d, 0x3c, 0xcb, 0x2c,
    0xfa, 0x50, 0x88, 0xe4, 0x24, 0x08, 0x84, 0x4c, 0x67, 0x3f, 0x63, 0xf7, 0x65, 0x97, 0xb0, 0x32,
    0x45, 0x90, 0x55, 0x06, 0x08, 0x6f, 0xdf, 0x5d, 0x6a, 0x58, 0xc0, 0x9a, 0x61, 0x41, 0xad, 0x74,
    0xa0, 0xa5, 0x71, 0x47, 0x21, 0x34, 0x3c, 0x31, 0x36, 0x10, 0x9a, 0x9a, 0xcc, 0x06, 0xae, 0xcf,
    0x94, 0x82, 0x35, 0xd9, 0x69, 0xf0, 0x28, 0x8b, 0xfd, 0xaa, 0x66, 0x95, 0x90, 0x2c, 0x9f, 0xb3,
    0xcf, 0x62, 0x1b, 0x86, 0x33, 0xca, 0x5b, 0x8e, 0x05, 0x9b, 0x91, 0xda, 0x1a, 0x37, 0xa0, 0xcc,
    0xab, 0x06, 0x29, 0x4a, 0x51, 0x16, 0x05, 0xc6, 0x00, 0xc1, 0xc0, 0x44, 0xb1, 0xe3, 0x70, 0x5e,
    0x85, 0xa3, 0xb0, 0x07, 0x10, 0xc8, 0x0e, 0x98, 0xf5, 0xf3, 0x86, 0x31, 0x50, 0x26, 0x48, 0x89,
    0x80, 0x25, 0xe0, 0x26, 0x5d, 0x89, 0x72, 0x5e, 0xd1, 0x94, 0xac, 0xb0, 0x49, 0x54, 0xef, 0xec,
    0x12, 0xa0, 0x1a, 0x66, 0xe4, 0x86, 0x93, 0x85, 0xec, 0x11, 0x7b, 0x86, 0x9a, 0x02, 0x81, 0x97,
    0xfd, 0x3a, 0x0b, 0x86, 0x95, 0xcb, 0xb9, 0x5e, 0xd1, 0x2b, 0xd4, 0xb7, 0x7d, 0x25, 0xaa, 0x48,
    0x55, 0x5c, 0xee, 0x69, 0xaa, 0xfd, 0xf2, 0xe3, 0x6c, 0xc9, 0x13, 0xdb, 0x1c, 0x45, 0x17, 0x8c,
    0xd8, 0x27, 0x93, 0xda, 0xa2, 0x1a, 0xa8, 0x99, 0x68, 0xe3, 0xd8, 0xd2, 0x4c, 0xe3, 0x48, 0x3b,
    0x6a, 0x55, 0x04, 0x71, 0xeb, 0x7e, 0xd0, 0x2a, 0x71, 0x68, 0xbf, 0x82, 0x43, 0xb8, 0x5a, 0xd8,
    0x91, 0x02, 0xba, 0x82, 0x16, 0xfc, 0x17, 0x75, 0xa1, 0xa4, 0xc4, 0x21, 0x1b, 0x08, 0x93, 0x73,
    0xa1, 0x9c, 0x82, 0xd6, 0x3b, 0x88, 0xed, 0x0e, 0x14, 0xc1, 0x0a, 0xed, 0x79, 0x5c, 0x15, 0x10,
    0x96, 0xc0, 0x87, 0xbf, 0xec, 0xd2, 0x92, 0x4d, 0xd1, 0xec, 0x73, 0x12, 0x78, 0x21, 0xae, 0x2d,
    0x8c, 0x48, 0x86, 0x26, 0x83, 0x47, 0x71, 0x13, 0x13, 0x50, 0x60, 0x05, 0x83, 0x55, 0x4d, 0xcf,
    0xb7, 0x2e, 0xe4, 0xc8, 0xb8, 0x8e, 0x41, 0x18, 0xda, 0x1c, 0x85, 0x4e, 0x62, 0x28, 0x6d, 0x63,
    0x1b, 0x64, 0xd6, 0x77, 0x55, 0xb0, 0x72, 0x3b, 0x7c, 0xee, 0x60, 0xce, 0x29, 0x2e, 0xde, 0x4b,
    0x33, 0xf7, 0x13, 0x38, 0x93, 0xf9, 0x66, 0x01, 0xaa, 0xbf, 0x51, 0x36, 0x0a, 0x19, 0x41, 0x38,
    0xb8, 0x67, 0x1f, 0x14, 0x62, 0x24, 0x3a, 0x2c, 0x43, 0x9c, 0x43, 0x22, 0xe1, 0xe2, 0x46, 0xe8,
    0xbd, 0x60, 0xf2, 0x5a, 0xb9, 0x48, 0xfb, 0xf1, 0x8d, 0xfa, 0x71, 0x1d, 0x19, 0x03, 0x0c, 0x43,
    0x17, 0x39, 0xbb, 0xd0, 0x22, 0x28, 0x19, 0x06, 0x81, 0xe3, 0x02, 0x92, 0x6e, 0x29, 0x8d, 0x77,
    0xe8, 0x15, 0x25, 0x3b, 0x52, 0x1e, 0x34, 0x50, 0x9d, 0xd8, 0xf0, 0x65, 0x3c, 0x02, 0x82, 0x0b,
    0xfa, 0x86, 0xad, 0xd2, 0x7b, 0x3d, 0x3b, 0x8a, 0x2c, 0xf1, 0xae, 0x4b, 0xe5, 0x03, 0xbe, 0xf2,
    0x46, 0xdb, 0x7c, 0xd0, 0xcd, 0x89, 0x12, 0x83, 0x50, 0x52, 0x13, 0xa0, 0x0a, 0x2d, 0x82, 0x25,
    0xa3, 0x5f, 0xfc, 0x77, 0x46, 0x4d, 0xcc, 0xe9, 0x22, 0x11, 0x9f, 0xd9, 0x15, 0xde, 0x64, 0x77,
    0xb9, 0x89, 0x9e, 0x6f, 0xba, 0x56, 0xe8, 0xfe, 0x99, 0x87, 0x7e, 0x93, 0xbb, 0xc0, 0xf2, 0x98,
    0xbd, 0xa0, 0x97, 0x05, 0x2c, 0xb8, 0x90, 0xb2, 0x34, 0x0a, 0x24, 0x4a, 0x18, 0x88, 0x77, 0x15,
    0xfe, 0xae, 0x80, 0xbe, 0xf8, 0x44, 0x03, 0xe9, 0x42, 0x67, 0xe0, 0xaf, 0x01, 0x74, 0x63, 0x68,
    0x26, 0x46, 0x95, 0xcd, 0x20, 0x2e, 0x0c, 0xa5, 0x67, 0x96, 0xf4, 0xab, 0x71, 0xa9, 0xdf, 0x34,
    0x02, 0x68, 0x3b, 0x8f, 0x0e, 0x04, 0x4c, 0x11, 0x33, 0xdc, 0xc8, 0xa3, 0x41, 0xa1, 0x45, 0x41,
    0xe6, 0x94, 0xd3, 0x0b, 0x95, 0x90, 0x7e, 0x89, 0xf6, 0xe3, 0x6a, 0x56, 0x94, 0x0f, 0xda, 0x84,
    0xd0, 0xa6, 0xae, 0x59, 0xb8, 0x2c, 0x2d, 0xf5, 0xd3, 0x21, 0xd2, 0xff, 0xd6, 0x31, 0x31, 0x64,
    0x28, 0x3c, 0xe9, 0x6f, 0x4b, 0x9f, 0x0a, 0xc0, 0x82, 0x40, 0x8b, 0x0a, 0xd2, 0x91, 0x7e, 0xde,
    0xf8, 0x14, 0xd0, 0xff, 0x87, 0xb6, 0x3e, 0x90, 0x2a, 0x78, 0xd3, 0x7d, 0x98, 0x64, 0x59, 0x42,
    0x77, 0xcc, 0x49, 0xe8, 0xb1, 0x0c, 0x00, 0xfc, 0xf8, 0xad, 0x08, 0xa7, 0x6f, 0x9f, 0xbe, 0x84,
    0x8a, 0x36, 0x87, 0x8f, 0x73, 0xff, 0xfd, 0x39, 0xca, 0x09, 0x26, 0x8f, 0xff, 0x6f, 0xfd, 0xe9,
    0x40, 0x42, 0x9e, 0x9b, 0x00
};

class VaapiDecoderVC1Test
    : public FactoryTest<IVideoDecoder, VaapiDecoderVC1> {
protected:
    /* invoked by gtest before the test */
    virtual void SetUp()
    {
        return;
    }

    /* invoked by gtest after the test */
    virtual void TearDown()
    {
        return;
    }
};

#define VAAPIDECODER_VC1_TEST(name) \
    TEST_F(VaapiDecoderVC1Test, name)

VAAPIDECODER_VC1_TEST(Factory)
{
    FactoryKeys mimeTypes;
    mimeTypes.push_back(YAMI_MIME_VC1);

    doFactoryTest(mimeTypes);
}

VAAPIDECODER_VC1_TEST(Decode_Simple)
{
    VaapiDecoderVC1 decoder;
    VideoConfigBuffer configBuffer;
    VideoDecodeBuffer buffer;

    memset(&configBuffer, 0, sizeof(VideoConfigBuffer));

    configBuffer.data = (uint8_t*)new uint8_t[5];
    configBuffer.data[0] = 0x4e;
    configBuffer.data[1] = 0x39;
    configBuffer.data[2] = 0x0a;
    configBuffer.data[3] = 0x81;
    configBuffer.data[4] = 0x00;
    configBuffer.size = 5;
    configBuffer.width = 320;
    configBuffer.height = 240;

    buffer.data = const_cast<uint8_t*>(g_SimpleVC1.data());
    buffer.size = g_SimpleVC1.size();
    buffer.timeStamp = 0;
    ASSERT_EQ(YAMI_SUCCESS, decoder.start(&configBuffer));
    ASSERT_EQ(YAMI_DECODE_FORMAT_CHANGE, decoder.decode(&buffer));
    ASSERT_EQ(YAMI_SUCCESS, decoder.decode(&buffer));
    /* pass a NULL buffer to flush output */
    ASSERT_EQ(YAMI_SUCCESS, decoder.decode(NULL));

    EXPECT_TRUE(decoder.getOutput());
    delete configBuffer.data;
}
}
