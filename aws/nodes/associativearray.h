#ifndef AWS_NODES_ASSOCIATIVEARRAY_H
#define AWS_NODES_ASSOCIATIVEARRAY_H

/*
 * aws/nodes/associativearray.h
 * AwesomeScript Associative Array
 * Author: Dominykas Djacenka
 * Email: Chaosteil@gmail.com
 */

#include <list>
#include <string>

#include "assignment.h"
#include "expression.h"

namespace AwS{
	namespace Nodes{
		class AssociativeArray : public Expression{
			public:
				AssociativeArray(std::list<Assignment*>* content)
					: Expression(), _content(content){
				}
				virtual ~AssociativeArray(){
					if(_content){
						for(std::list<Assignment*>::iterator i = _content->begin(); i != _content->end(); ++i){
							if(*i)delete *i;
						}
						delete _content;
					}
				}

				const std::list<Assignment*>& getContent() const{ return *_content; }

				void translatePhp(std::ostream& output, TranslateSettings& settings) const throw(NodeException){
					output << "array(" << std::endl;

					bool begin = true;
					for(std::list<Assignment*>::iterator i = _content->begin(); i != _content->end(); ++i){
						if(begin == false)
							output << ", " << std::endl;

						output << "'" << (*i)->getVariable()->getName() << "'";
						output << " => ";
						(*i)->getValue()->translatePhp(output, settings);

						begin = false;
					}

					output << ")";
				}
			private:
				std::list<Assignment*>* _content;
		};
	};
};

#endif
