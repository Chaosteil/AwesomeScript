#ifndef AWS_NODES_BREAKSTATEMENT_H
#define AWS_NODES_BREAKSTATEMENT_H

/*
 * aws/nodes/breakstatement.h
 * AwesomeScript Break Statement
 * Author: Dominykas Djacenka
 * Email: Chaosteil@gmail.com
 */

#include "statement.h"

namespace AwS{
	namespace Nodes{
		class BreakStatement : public Statement{
			public:
				BreakStatement()
					: Statement(){
				}

				virtual ~BreakStatement(){}

				void translatePhp(std::ostream& output, TranslateSettings& settings) const throw(NodeException){
					output << "break;" << std::endl;
				}
		};
	};
};

#endif
