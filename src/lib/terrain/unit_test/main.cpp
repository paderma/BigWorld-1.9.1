/******************************************************************************
BigWorld Technology
Copyright BigWorld Pty, Ltd.
All Rights Reserved. Commercial in confidence.

WARNING: This computer program is protected by copyright law and international
treaties. Unauthorized use, reproduction or distribution of this program, or
any portion of this program, may result in the imposition of civil and
criminal penalties as provided by law.
******************************************************************************/

#include "pch.hpp"
#include "cstdmf/cstdmf.hpp"
#include "cstdmf/memory_tracker.hpp"
//#include "resmgr/auto_config.hpp"
#include "moo/init.hpp"

#include "unit_test_lib/unit_test.hpp"

int main( int argc, char* argv[] )
{
#ifdef ENABLE_MEMTRACKER
	MemTracker::instance().setCrashOnLeak( true );
#endif

	new CStdMf;
#ifndef MF_SERVER
	Moo::init();
#endif

	int ret = BWUnitTest::runTest( "terrain", argc, argv );

#ifndef MF_SERVER
	Moo::fini();
#endif
	delete CStdMf::pInstance();

	return ret;
}

// main.cpp