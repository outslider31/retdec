/**
 * @file include/bin2llvmir/optimizations/dump_module/dump_module.h
 * @brief This is a utility debug pass that only dumps the module into LLVM IR.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

#ifndef BIN2LLVMIR_OPTIMIZATIONS_DUMP_MODULE_DUMP_MODULE_H
#define BIN2LLVMIR_OPTIMIZATIONS_DUMP_MODULE_DUMP_MODULE_H

#include <llvm/IR/Module.h>
#include <llvm/Pass.h>

namespace bin2llvmir {

class DumpModule : public llvm::ModulePass
{
	public:
		static char ID;
		DumpModule();
		virtual bool runOnModule(llvm::Module& M) override;
};

} // namespace bin2llvmir

#endif
