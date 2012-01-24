//////////////////////////////////////////////////////////////////////////
//																		//
//				Copyright (C) 2008  Brendan Borthwick					//
//																		//
//////////////////////////////////////////////////////////////////////////

#ifndef SPRITEFILE_H
#define SPRITEFILE_H

#include <QThread>

#include "tibiasprite.h"
#include "tibiafile.h"

class UserThread;

class SpriteFile : public TibiaFile
{
	Q_OBJECT

public:
	SpriteFile( QObject* parent );
	virtual ~SpriteFile( void );

	virtual bool createNew( void );
	virtual bool isLoaded( void ) const { return m_loaded; };
	virtual void unload( void );
	virtual bool load( const QString& ) { return false; };
	//virtual bool save( const QString& );
	virtual bool save( const QString& ) { return false; };
	virtual bool idle( const QString&, bool );

	virtual SpriteFile* getSpriteFile() { return this; };
	virtual const SpriteFile* getSpriteFile() const { return this; };

	quint16 getCount( void ) const { return m_count; };
	void setCount( quint16 count ) { m_count = count; };

	UserThread* getThread() const { return m_thread; };

	TibiaSprite getSprite( quint16 id );
	TibiaSprite loadSprite( quint16 spriteId );
	
private:
	quint16 m_count;
	UserThread* m_thread;

	bool m_loaded;
	mutable QMutex mutex;
};

#endif // SPRITEFILE_H
