#ifndef ARTitle_H
#define ARTitle_H

/*
  GUIDO Library
  Copyright (C) 2002  Holger Hoos, Juergen Kilian, Kai Renz
  Copyright (C) 2002-2017 Grame

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr

*/

#include "ARText.h"

/** \brief not yet documented
*/
class ARTitle : public ARText
{
	public:
					 ARTitle();
		virtual     ~ARTitle() {}

		virtual int			getOrder() const		{ return kTitleOrder; }
		virtual const char*	getParamsStr() const	{ return kARTitleParams; };
		virtual const char*	getTagName() const		{ return "ARTitle"; };
		virtual std::string getGMNName() const		{ return "\\title"; };

		const char*  getName() const;
		const char*  getPageFormat() const;
};

#endif
