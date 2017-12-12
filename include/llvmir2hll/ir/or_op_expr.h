/**
* @file include/llvmir2hll/ir/or_op_expr.h
* @brief A logical "or" operator.
* @copyright (c) 2017 Avast Software, licensed under the MIT license
*/

#ifndef LLVMIR2HLL_IR_OR_OP_EXPR_H
#define LLVMIR2HLL_IR_OR_OP_EXPR_H

#include "llvmir2hll/ir/binary_op_expr.h"
#include "llvmir2hll/support/smart_ptr.h"

namespace llvmir2hll {

class Expression;
class Visitor;

/**
* @brief A logical "or" operator.
*
* This operator has the same meaning as the '||' operator in C.
*
* Use create() to create instances. Instances of this class have reference
* object semantics. This class is not meant to be subclassed.
*/
class OrOpExpr final: public BinaryOpExpr {
public:
	static ShPtr<OrOpExpr> create(ShPtr<Expression> op1,
		ShPtr<Expression> op2);

	virtual ~OrOpExpr() override;

	virtual bool isEqualTo(ShPtr<Value> otherValue) const override;
	virtual ShPtr<Value> clone() override;
	virtual ShPtr<Type> getType() const override;

	/// @name Visitor Interface
	/// @{
	virtual void accept(Visitor *v) override;
	/// @}

private:
	// Since instances are created by calling the static function create(), the
	// constructor can be private.
	OrOpExpr(ShPtr<Expression> op1, ShPtr<Expression> op2);
};

} // namespace llvmir2hll

#endif
