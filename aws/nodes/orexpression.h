#ifndef AWS_NODES_OREXPRESSION_H
#define AWS_NODES_OREXPRESSION_H

/*
 * aws/nodes/orexpression.h
 * AwesomeScript Or Expression
 * Author: Dominykas Djacenka
 * Email: Chaosteil@gmail.com
 */

#include "binaryexpression.h"

namespace AwS{
	namespace Nodes{
		class OrExpression : public BinaryExpression{
			public:
				OrExpression(Expression* left, Expression* right)
					: BinaryExpression(left, right){
				}
				virtual ~OrExpression(){}

				void translatePhp(std::ostream& output, TranslateSettings& settings) const throw(NodeException){
					getLeft()->translatePhp(output, settings);
					output << " || ";
					getRight()->translatePhp(output, settings);
				}
		};
	};
};

#endif
