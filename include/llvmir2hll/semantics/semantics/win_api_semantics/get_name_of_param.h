/**
* @file include/llvmir2hll/semantics/semantics/win_api_semantics/get_name_of_param.h
* @brief Provides function getNameOfParam() for WinAPISemantics in the
*        semantics::win_api namespace.
* @copyright (c) 2017 Avast Software, licensed under the MIT license
*/

#ifndef LLVMIR2HLL_SEMANTICS_SEMANTICS_WIN_API_SEMANTICS_GET_NAME_OF_PARAM_H
#define LLVMIR2HLL_SEMANTICS_SEMANTICS_WIN_API_SEMANTICS_GET_NAME_OF_PARAM_H

#include <string>

#include "llvmir2hll/support/maybe.h"

namespace llvmir2hll {
namespace semantics {
namespace win_api {

Maybe<std::string> getNameOfParam(const std::string &funcName,
	unsigned paramPos);

} // namespace win_api
} // namespace semantics
} // namespace llvmir2hll

#endif
