/**
* @file include/llvmir2hll/ir/comma_op_expr.h
* @brief A comma operator.
* @copyright (c) 2017 Avast Software, licensed under the MIT license
*/

#ifndef LLVMIR2HLL_IR_COMMA_OP_EXPR_H
#define LLVMIR2HLL_IR_COMMA_OP_EXPR_H

#include "llvmir2hll/ir/binary_op_expr.h"
#include "llvmir2hll/support/smart_ptr.h"

namespace llvmir2hll {

class Expression;
class Visitor;

/**
* @brief A comma operator.
*
* This operator has the same meaning as the ',' operator in C.
*
* Use create() to create instances. Instances of this class have reference
* object semantics. This class is not meant to be subclassed.
*/
class CommaOpExpr final: public BinaryOpExpr {
public:
	static ShPtr<CommaOpExpr> create(ShPtr<Expression> op1,
		ShPtr<Expression> op2);

	virtual ~CommaOpExpr() override;

	virtual bool isEqualTo(ShPtr<Value> otherValue) const override;
	virtual ShPtr<Value> clone() override;

	/// @name Visitor Interface
	/// @{
	virtual void accept(Visitor *v) override;
	/// @}

private:
	// Since instances are created by calling the static function create(), the
	// constructor can be private.
	CommaOpExpr(ShPtr<Expression> op1, ShPtr<Expression> op2);
};

} // namespace llvmir2hll

#endif
