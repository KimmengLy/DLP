package com.paracamplus.ilp1.ilp1tme1.sequence;

import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interfaces.IASTfactory;

public class ASTfactory extends com.paracamplus.ilp1.ast.ASTfactory implements IASTfactory{
	
	public IASTsequence newSequence(IASTexpression [] asts) {
		return new ASTsequence(asts);
	}
}
