/***************************************************************************
 *   Copyright (C) 2006 by FThauer FHammer   *
 *   f.thauer@web.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef ENGINEFACTORY_H
#define ENGINEFACTORY_H

#include "boardinterface.h"
#include "handinterface.h"
#include "playerinterface.h"
#include "berointerface.h"

#include <boost/shared_ptr.hpp>


class EngineFactory{
public:
    
	virtual ~EngineFactory();
		
	virtual HandInterface* createHand(boost::shared_ptr<EngineFactory> f, GuiInterface *g, BoardInterface *b, /*std::vector<boost::shared_ptr<PlayerInterface> > sl_old,*/ PlayerList sl, PlayerList apl, PlayerList rpl, int id, int sP, int dP, int sB,int sC) =0;
	virtual BoardInterface* createBoard() =0;
	virtual boost::shared_ptr<PlayerInterface> createPlayer(BoardInterface *b, int id, unsigned uniqueId, PlayerType type, std::string name, std::string avatar, int sC, bool aS, int mB) =0;
	virtual std::vector<boost::shared_ptr<BeRoInterface> > createBeRo(HandInterface* hi, int id, unsigned dP, int sB) =0;
};

#endif
