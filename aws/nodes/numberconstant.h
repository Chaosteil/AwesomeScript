#ifndef AWS_NODES_NUMBERCONSTANT_H
#define AWS_NODES_NUMBERCONSTANT_H

/*
 * aws/nodes/numberconstant.h
 * AwesomeScript Number Constant
 * Author: Dominykas Djacenka
 * Email: Chaosteil@gmail.com
 */

#include "expression.h"

namespace AwS{
	namespace Nodes{
		class NumberConstant : public Expression{
			public:
				NumberConstant(const float& content)
					: Expression(), _content(content){
				}
				virtual ~NumberConstant(){}

				const float& getContent() const{return _content; }

				void translatePhp(std::ostream& output, TranslateSettings& settings) const throw(NodeException){
					output << _content;
				}
			private:
				const float _content;
		};
	};
};

#endif
