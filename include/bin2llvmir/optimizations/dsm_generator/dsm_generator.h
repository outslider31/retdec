/**
 * @file include/bin2llvmir/optimizations/dsm_generator/dsm_generator.h
 * @brief Produce DSM output.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

#ifndef BIN2LLVMIR_OPTIMIZATIONS_DSM_GENERATOR_DSM_GENERATOR_H
#define BIN2LLVMIR_OPTIMIZATIONS_DSM_GENERATOR_DSM_GENERATOR_H

#include <ostream>

#include <llvm/IR/Module.h>
#include <llvm/Pass.h>

#include "bin2llvmir/providers/asm_instruction.h"
#include "bin2llvmir/providers/config.h"
#include "bin2llvmir/providers/fileimage.h"
#include "bin2llvmir/utils/instruction.h"

namespace bin2llvmir {

class DsmGenerator : public llvm::ModulePass
{
	public:
		static char ID;
		DsmGenerator();
		virtual bool runOnModule(llvm::Module& m) override;
		bool runOnModuleCustom(
				llvm::Module& m,
				Config* c,
				FileImage* objf,
				std::ostream& ret);

	private:
		void run(std::ostream& ret);
		void generateHeader(std::ostream& ret);
		void generateCode(std::ostream& ret);
		void generateCodeSeg(
				const loader::Segment* seg,
				std::ostream& ret);
		void generateFunction(
				retdec_config::Function* fnc,
				std::ostream& ret);
		void generateInstruction(AsmInstruction& ai, std::ostream& ret);
		void generateData(std::ostream& ret);
		void generateDataSeg(
				const loader::Segment* seg,
				std::ostream& ret);
		void generateDataRange(
				tl_cpputils::Address start,
				tl_cpputils::Address end,
				std::ostream& ret);
		void generateAlignedAddress(
				tl_cpputils::Address addr,
				std::ostream& ret);

		void getAsmInstructionHex(AsmInstruction& ai, std::ostream& ret);
		std::string processInstructionDsm(AsmInstruction& ai);
		void generateData(
				std::ostream& ret,
				tl_cpputils::Address start,
				std::size_t size,
				const std::string& objVal = "");
		std::string escapeString(const std::string& str);
		std::string reduceNegativeNumbers(const std::string& str);
		void findLongestInstruction();
		void findLongestAddress();
		std::string getString(
				const retdec_config::Object* cgv,
				const llvm::ConstantDataArray* cda);

		std::string getFunctionName(llvm::Function* f) const;
		std::string getFunctionName(retdec_config::Function* f) const;

	private:
		llvm::Module* _module = nullptr;
		Config* _config = nullptr;
		FileImage* _objf = nullptr;
		std::size_t _longestInst = 0;
		std::size_t _longestAddr = 0;
		std::map<tl_cpputils::Address, retdec_config::Function*> _addr2fnc;

		const std::size_t DATA_SEGMENT_LINE    = 16;
		const std::string ALIGN = "   ";
		const std::string INSTR_SEPARATOR = "\t"; // maybe "\t"
};

} // namespace bin2llvmir

#endif
