#ifndef GRSpring_H
#define GRSpring_H

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

#include "kf_ilist.h"
#include <typeinfo>

// #include "ARMusicalObject.h"
#include "GRNotationElement.h"
#include "GRVoice.h"

typedef KF_IPointerList<GRNotationElement> GROList;	// TODO: replace by std::vector (easy)
typedef KF_IPointerList<GRVoice> GRVList;// TODO: replace by std::vector (easy)

class GRRod;
class GRSystem;
class GRStaff;

class GRSpaceForceFunction2;
class GRSpringCollider;


/** \brief Used with rods and space fore functions
*/


class GRSpring  
{
	friend class GRSpaceForceFunction2;
	friend class GRRod;
	friend class GRSystem;
public:

			GRSpring(const TYPE_TIMEPOSITION  & vtp, const TYPE_DURATION & vdur, float spring, float propRender);
			GRSpring( GRNotationElement *, GRVoice *, float spring, float propRender );

	virtual ~GRSpring();

	void OnDraw( VGDevice & hdc ) const;
	bool containsBar() const;

	// A routine to check local collisions
	void checkLocalCollisions ();
	
	// this routine looks at the GRSpringCollider of this instance of GRSpring and
	// at the GRSpringCollider of nextspring.
	// It finds matching poslists and returns the maximum needed distance ...
	float	GetMaxDistance(GRSpring * nextspring);

	float	stretchWithForce(float newforce);
	bool	hasStaffAndType(const GRStaff * grstaff, const std::type_info & ti);
	float	set_const(float dc);
	float	recalcConstant();
	void	addElement(GRNotationElement * el,GRVoice * vce);
	bool	hasType(const std::type_info & ti);
    bool	hasGraceNote();
	void	setNoExtent();
	int		removeElement(GRNotationElement * el);
	int		setGRPositionX(float p_posx);
	void	setGRSpringID();

	float	getExtent() const			{ return fX; }
	void	setID(int _id);
	int		getID() const;
	float	getForce() const			{ return fForce; }
	float	getConstant() const			{ return fSconst; }

	virtual const GRNotationElement *	getFirstGRO() const;
	virtual GuidoPos					getFirstGROPosition();
	virtual const GRNotationElement *	getNextGRO(GuidoPos & pos) const;
	virtual float apply_force(float df);
	virtual float change_x(float dx);
	virtual float change_force(float df);
	virtual float change_const(float dc);
	virtual float change_dur(const TYPE_DURATION & ndur );
	virtual float setlength(float dx);


	virtual const TYPE_DURATION & getTimePosition() const	{ return fTp; }
	virtual const TYPE_DURATION & getDuration() const		{ return fDur; }

	int operator<(const GRSpring & spr) const;


	static float defconst(const TYPE_DURATION &, float spring);
	static float defconst(float dur, float spring );

	int isCommonSpring(int numvoices) const;

	// this flag is set to true, if the spring really has an element of its duration
	// this helps in spacing-issues.
	// (if the spring has no element of this type the average building process during the neighbourhoodcheck is made easier)
	bool	fHasDurElement;

	int		fIsfrozen;
	float	fPosx;	// (JB) was int

    float setProportionalForce();

protected:
	float calcconst(GRNotationElement * grn);
	TYPE_TIMEPOSITION fTp;
	TYPE_DURATION     fDur;
	int				  fId;      // a definite ID

	GRSpringCollider *fSprcol;
	float fFuncpar;
	float fProportionalRendering;

private:
	float		fForce;
	float		fX;
	float		fSconst;  // spring-constants
    bool		fIsProportionalElement;

	// a routine to check the accidental-collisions ...
	void		checkAccidentalCollisions();

	// A list of GObjects, that this spring includes
	GROList			  fGrolst;  //
	GRVList		      fGrvlst;
};

int sprcomp(const GRSpring &gr1,const GRSpring &gr2);
int sprpcomp(const GRSpring *gr1,const GRSpring *gr2);

#endif
