package com.paracamplus.ilp1.ilp1tme1.sequence;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

import com.paracamplus.ilp1.ast.ASTprogram;
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interfaces.IASTfactory;
import com.paracamplus.ilp1.interfaces.IASTprogram;

public class ASTsequenceTest {
	private  IASTfactory factory = new ASTfactory();

	@Test
	public void testUno() throws Exception {
		IASTexpression int1 = factory.newIntegerConstant("5");
		IASTexpression int2 = factory.newIntegerConstant("6");
		IASTexpression expBin = factory.newBinaryOperation(factory.newOperator("+"),
								   int1,
								   int2);
		
		IASTexpression[] list = new IASTexpression[3];
		list[0] = int1;
		list[1] = int2;
		list[2] = expBin;
		
		IASTexpression expSeq = factory.newSequence(list);
		
		IASTprogram prog = new ASTprogram(expSeq);
		
		assertTrue(prog.getBody() instanceof IASTsequence);
		IASTsequence iast = (IASTsequence) prog.getBody();
		
		IASTexpression[] exps = iast.getExpressions();
		assertNotNull(exps);
		
		assertTrue(exps.length == 3);
		IASTexpression[] expsLast = iast.getAllButLastInstructions();
		assertEquals(2, expsLast.length);
		System.out.println("Mec, c'est incroyable !");
	}   
}