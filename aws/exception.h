#ifndef AWS_EXCEPTION_H
#define AWS_EXCEPTION_H

/*
 * aws/exception.h
 * AwesomeScript Exception
 * Author: Dominykas Djacenka
 * Email: Chaosteil@gmail.com
 */

#include <string>

namespace AwS{
	//! Used for throwing errors of the Tokenizer, Parser and Translator.
	/*!
	 * Each error has its own error code used to define each error thrown
	 * by the AwS classes. TODO It can be later translated to normal
	 * error codes and their strings, for user output.
	 */
	class Exception{
		public:
			//! A type for each exception
			enum ExceptionType{
				None = 0, //!< No error (No exception)
				DefaultError = 100, //!< Default Error for everything unrelated directly to AwS
				ReadingError = 200, //!< Default Syntax Error.
				ParsingError = 300, //!< Default Parsing Error.
				ConvertError = 400 //!< Default Converting Error.
			};

			//! Constructor.
			/*!
			 * \param type The type of the Exception, also marks the error code to be passed.
			 * \param id The additional id of the message.
			 * \param message The human readable error message, should provide additional information about the specific error.
			 */
			Exception(ExceptionType type, int id, const std::string& message);
			//! Destructor.
			~Exception();
			//! The human readable message of this Exception.
			/*!
			 * \return The currently stored error message in this Exception.
			 */
			const std::string& getMessage() const;
			//! Gets the type of the current Exception, also allowing to retrieve the Error ID of it.
			/*!
			 * \return The type of the Exception. Each error returns an own errortype, unique for the type of error.
			 */
			ExceptionType getType() const;

			//! Returns the complete ID of the Exception.
			/*!
			 * \return The Type of the Exception + the subID of the Exception, as specified in the constructor.
			 */
			int getId() const;
		private:
			const ExceptionType _type; //!< The type of the Exception.
			const int _id; // The subID of the exception.
			const std::string _message; //!< The stored human readable message.
	};
};

#endif
