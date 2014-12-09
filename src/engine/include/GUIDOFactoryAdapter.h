#ifndef GUIDOFACTORYADAPTER_H
#define GUIDOFACTORYADAPTER_H
/*
  GUIDO Library
  Copyright (C) 2014	Grame

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr

*/

#include "GUIDOFactory.h"
#include <string>

class GUIDOFactoryAdapter
{
	public:
		GUIDOFactoryAdapter();

		// ----------------------------------------------------------------------------
		/** \brief Opens the Guido Factory.

			Must be called before any other call to the Guido Factory API.
			\return a ar factory handler or null if error
		*/
		ARFactoryHandler open();

		// ----------------------------------------------------------------------------
		/** \brief Closes the Guido Factory.

			Must be called to release the factory associated resources.
		*/
		void close(ARFactoryHandler inFactory);

		// ----------------------------------------------------------------------------
		/** \brief Creates and opens a new music score.

			The function modifies the factory state: the new score becomes
			the current factory score.
			It fails if a music score is already opened.
			A music score has to be closed using \p GuidoFactoryCloseMusic()
			\return an integer that is an error code if not null.
		*/
		GuidoErrCode openMusic(ARFactoryHandler inFactory);

		// ----------------------------------------------------------------------------
		/** \brief Closes the current music score.

			The function modifies the factory state if a music score is currently opened:
			the current factory score is set to null.
			It fails if no music score is
			opened.
			You must not have pending events nor pending voice at this point.

			The logicical music layout (conversion from abstract to abstract representation)
			is part of the function operations.
			Next, the caller is expected to call \p GuidoFactoryMakeGR() with the returned value
			in order to proceed with the graphical score layout.

			\return a GUIDO handler to the new AR structure, or 0.
			\sa \p GuidoFactoryMakeGR()
		*/
		ARHandler closeMusic(ARFactoryHandler inFactory);

		// ----------------------------------------------------------------------------
		/** \brief Creates and opens a new voice.

			The function modifies the factory state:
			the new voice becomes the current factory voice.
			It fails if a voice is already opened.
			A voice has to be closed using \p GuidoFactoryCloseVoice()
			Voices are similar to sequence is GMN.

			\return an error code
		*/
		GuidoErrCode openVoice(ARFactoryHandler inFactory);

		// ----------------------------------------------------------------------------
		/** \brief Closes the current voice.

			The function modifies the factory state if a voice is currently opened:
			the current factory voice is set to null.
			It fails if no voice is opened.
			You must not have pending events at this point.
			The voice is first converted to its normal form and next added to the current score.

			\return an error code
		*/
		GuidoErrCode closeVoice(ARFactoryHandler inFactory);

		// ----------------------------------------------------------------------------
		/** \brief Creates and open a new chord.

			The function modifies the factory state:
			the new chord becomes the current factory chord.
			It fails if a chord is already opened.
			A chord has to be closed using \p GuidoFactoryCloseChord()

			\return an error code
		*/
		GuidoErrCode openChord(ARFactoryHandler inFactory);

		// ----------------------------------------------------------------------------
		/** \brief Closes the current chord.

			The function modifies the factory state if a chord is currently opened:
			the current factory chord is set to null.
			It fails if no chord is opened.
			The chord is added to the current voice.
			\return an error code
		*/
		GuidoErrCode closeChord(ARFactoryHandler inFactory);

		// ----------------------------------------------------------------------------
		/** \brief Begins a new chord note commata.

			Called to tell the factory that a new chord-voice
			 is beginning. This is important for the ranges that need to
			  be added (dispdur and shareStem)

			\return an error code
		*/
		GuidoErrCode insertCommata(ARFactoryHandler inFactory);

		// ----------------------------------------------------------------------------
		/** \brief Creates and opens a new event (note or rest).

			The function modifies the factory state:
			the new event becomes the current factory event.
			It fails if an event is already opened.
			An event has to be closed using \p GuidoFactoryCloseEvent()
			\return an error code
		*/
		GuidoErrCode openEvent(ARFactoryHandler inFactory, const std::string inEventName);

		// ----------------------------------------------------------------------------
		/** \brief Closes the current event.

			The function modifies the factory state if an event is currently opened:
			the current factory event is set to null.
			It fails if no event is opened.
			The event is added to the current voice.

			\return an error code
		*/
		GuidoErrCode closeEvent(ARFactoryHandler inFactory);

		// ----------------------------------------------------------------------------
		/** \brief Adds a sharp to the current event.

			The current event must be a note.
			\return an error code
		*/
		GuidoErrCode addSharp(ARFactoryHandler inFactory);

		// ----------------------------------------------------------------------------
		/** \brief Add a flat to the current event.

			The current event must be a note.
			\return an error code.
		*/
		GuidoErrCode addFlat(ARFactoryHandler inFactory);

		// ----------------------------------------------------------------------------
		/** \brief Sets the number of dots the current event.
			\param inFactory a handler to a Guido Factory (created with GuidoFactoryOpen)
			\param dots the number of dots to be carried by the current event.
			\return an error code.
		*/
		GuidoErrCode setEventDots(ARFactoryHandler inFactory, int dots);

		// ----------------------------------------------------------------------------
		/** \brief Sets the accidentals of the current event.
			\param inFactory a handler to a Guido Factory (created with GuidoFactoryOpen)
			\param accident: positive values are used for sharp and negative values for flats
			\return an error code.
		*/
		GuidoErrCode setEventAccidentals(ARFactoryHandler inFactory, int accident);

		// ----------------------------------------------------------------------------
		/** \brief Sets the register (octave) of the current event.

			The current  event must be a note.
			The register becomes the current register ie  next notes will carry this
			register until otherwise specified.

			\param inFactory a handler to a Guido Factory (created with GuidoFactoryOpen)
			\param octave is an integer value indicating the octave of the note where
			\e a1 is \e A 440Hz. All octaves start with the pitch class \e c.
			\return an error code.
		*/
		GuidoErrCode setOctave(ARFactoryHandler inFactory, int octave);

		// ----------------------------------------------------------------------------
		/** \brief Sets the duration of the current event.

			Durations are expressed as fractional value of a whole note: for example,
			a quarter note duration is 1/4.
			The duration becomes the current duration ie  next notes will carry this
			duration until otherwise specified.
			\param inFactory a handler to a Guido Factory (created with GuidoFactoryOpen)
			\param numerator: the rational duration numerator
			\param denominator: the rational duration denominator
			\return an error code.
		*/
		GuidoErrCode setDuration(ARFactoryHandler inFactory, int numerator, int denominator);

		// ----------------------------------------------------------------------------
		/** \brief Add a tag to the current voice.

			\param inFactory a handler to a Guido Factory (created with GuidoFactoryOpen)
			\param name: the tag name
			\param tagID: is the number that the parser generates for advanced GUIDO
			\return an error code.
		*/
		GuidoErrCode openTag(ARFactoryHandler inFactory, const std::string & name, long tagID);

		// ----------------------------------------------------------------------------
		/** \brief Add a tag to the current voice.

			\param inFactory a handler to a Guido Factory (created with GuidoFactoryOpen)
			\param name: the tag name
			\param tagID: is the number that the parser generates for advanced GUIDO
			\return an error code.
		*/
		GuidoErrCode openRangeTag(ARFactoryHandler inFactory, const std::string& name, long tagID);


		// ----------------------------------------------------------------------------
		/** \brief Indicates the end of a range tag.

			The function is applied to the current tag.
			It must be called when the end of a tag's range
			has been reached.
			\param inFactory a handler to a Guido Factory (created with GuidoFactoryOpen)
			\return an error code.
		*/
		GuidoErrCode endTag(ARFactoryHandler inFactory);

		// ----------------------------------------------------------------------------
		/** \brief Closes the current tag.

			The function is applied to the current tag.
			Must be called after parameter and before the range.
		\n  With the following examples:
		- tag<1,2,3>(c d e) 	: call the function before parsing c
		- tag<1,2> c d          : call the function before parsing c

			\param inFactory a handler to a Guido Factory (created with GuidoFactoryOpen)
			\return an error code.
		*/
		GuidoErrCode closeTag(ARFactoryHandler inFactory);

		// ----------------------------------------------------------------------------
		/** \brief Adds a new string parameter to the current tag.

			\param inFactory a handler to a Guido Factory (created with GuidoFactoryOpen)
			\param val: the string parameter value
			\return an error code.
		*/
		GuidoErrCode addTagParameterString(ARFactoryHandler inFactory, const std::string & val);

		// ----------------------------------------------------------------------------
		/** \brief  Adds a new integer parameter to the current tag.

			\param inFactory a handler to a Guido Factory (created with GuidoFactoryOpen)
			\param val: the parameter value
			\return an error code.
		*/
		GuidoErrCode addTagParameterInt(ARFactoryHandler inFactory, int val);

		// ----------------------------------------------------------------------------
		/** \brief Adds a new floating-point parameter to the current tag.

			\param inFactory a handler to a Guido Factory (created with GuidoFactoryOpen)
			\param val: the parameter value
			\return an error code.
		*/
		GuidoErrCode addTagParameterFloat(ARFactoryHandler inFactory, double val);

		// ----------------------------------------------------------------------------
		/** \brief Defines the name (when applicable) of the last added tag-parameter

			\param inFactory a handler to a Guido Factory (created with GuidoFactoryOpen)
			\param name: the tag parameter name
			\return an error code.
		*/
		GuidoErrCode setParameterName(ARFactoryHandler inFactory, const std::string& name);

		// ----------------------------------------------------------------------------
		/** \brief Defines the unit of the last added tag-parameter

			\param inFactory a handler to a Guido Factory (created with GuidoFactoryOpen)
			\param unit: a string defining the unit. The following units are supported:
		- \p m - meter
		- \p cm - centimeter
		- \p mm - millimeter
		- \p in - inch
		- \p pt - point (= 1/72.27 inch)
		- \p pc - pica (= 12pt)
		- \p hs - halfspace (half of the space between  two lines of the current staff)
		- \p rl - relative measure in percent  (used for positioning on score page)
			\return an error code.
		*/
		GuidoErrCode setParameterUnit(ARFactoryHandler inFactory, const std::string& unit);
};

#endif // GUIDOFACTORYADAPTER_H
