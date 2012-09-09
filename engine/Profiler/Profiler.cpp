#include "../include/Profiler.h"
#include "../include/ProfilerBlock.h"
#include "../include/KgeMemory.h"

namespace kge
{
	//------------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------------
	Profiler::Profiler()
	{

	} // Constructor

	//------------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------------
	Profiler::~Profiler()
	{

	} // Destructor

	//------------------------------------------------------------------------------------
	// Return the profiler pointer
	//------------------------------------------------------------------------------------
	Profiler* Profiler::GetPointer()
	{
		static Profiler sp;
		
		return &sp;

	} // GetPointer

	//------------------------------------------------------------------------------------
	// Returns the block with its name
	//------------------------------------------------------------------------------------
	ProfilerBlock* Profiler::GetBlock( const core::stringc& sName )
	{
		std::map<core::stringc, ProfilerBlock*>::iterator it;
		it = m_mBlocks.find(sName);

		if (it != m_mBlocks.end())
			return it->second;

		// Create a new block
		ProfilerBlock*	pPB = KGE_NEW(ProfilerBlock)(sName);

		return pPB;

	} // GetBlock

} // kge
