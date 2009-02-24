#ifndef AWS_NODES_IFSTATEMENT_H
#define AWS_NODES_IFSTATEMENT_H

/*
 * aws/nodes/ifstatement.h
 * AwesomeScript If Statement
 * Author: Dominykas Djacenka
 * Email: Chaosteil@gmail.com
 */

#include "statement.h"

namespace AwS{
	namespace Nodes{
		class IfStatement : public Statement{
			public:
				IfStatement(Expression* expression,
					Statement* trueStatement, Statement* falseStatement)
					: Statement(), _expression(expression),
					_trueStatement(trueStatement), _falseStatement(falseStatement){
					
					std::cout << "IfStatement" << std::endl;
				}
				virtual ~IfStatement(){
					if(_expression)delete _expression;
					if(_trueStatement)delete _trueStatement;
					if(_falseStatement)delete _falseStatement;
				}
				
				const Expression* getExpression() const{ return _expression; }
				const Statement* getTrue() const{ return _trueStatement; }
				const Statement* getFalse() const{ return _falseStatement; }
			private:
				const Expression* _expression;
				const Statement* _trueStatement;
				const Statement* _falseStatement;
		};
	};
};

#endif