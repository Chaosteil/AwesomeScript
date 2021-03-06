#ifndef AWS_NODES_DIVISION_H
#define AWS_NODES_DIVISION_H

/*
 * aws/nodes/division.h
 * AwesomeScript Division
 * Author: Dominykas Djacenka
 * Email: Chaosteil@gmail.com
 */

#include "binaryexpression.h"

namespace AwS{
	namespace Nodes{
		class Division : public BinaryExpression{
			public:
				Division(Expression* left, Expression* right)
					: BinaryExpression(left, right){
				}
				virtual ~Division(){}

				void translatePhp(std::ostream& output, TranslateSettings& settings) const throw(NodeException){
					getLeft()->translatePhp(output, settings);
					output << " / ";
					getRight()->translatePhp(output, settings);
				}
		};
	};
};

#endif
