package com.paracamplus.ilp1.ilp1tme1.sequence;

import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;

public class ASTsequence extends com.paracamplus.ilp1.ast.ASTsequence implements IASTsequence{
		
	public ASTsequence(IASTexpression[] expressions) {
		super(expressions);
	}

	@Override
	public IASTexpression[] getAllButLastInstructions() throws EvaluationException {
		IASTexpression[] expr = this.getExpressions();
		int length = expr.length - 1;
		IASTexpression[] res = new IASTexpression[length];
		
		for(int i=0; i<length; i++) {
			res[i] = expr[i];
		}
		
		return res;
	}

}
