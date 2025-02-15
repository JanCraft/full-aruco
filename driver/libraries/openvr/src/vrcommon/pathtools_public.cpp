INDX( 	 &��           (   �  �       ~                     Z�     p \     X�     ��P� �=̱'���P���P� �      ^r              b a n e n r - b g . j p g     Z�     p Z     X�     ��P� �=̱'���P���P� �      ^r              B A N E N R ~ 1 . J P G       _�     � j     X�     ��P� ^�u���F�P���P�H       D               b l a c k _ o p a c i t y _ 2 5 . p n g      _�     p Z     X�     ��P� ^�u���F�P���P�H       D               B L A C K _  1 . P N G       a�     ` P     X�     �F�P� ^�u���F�P��F�P� `      ?X              b o x . p n g c�     x b     X�     n�P� ^�u����P�n�P��       �               b t n - b u y - i c o n . p n g       h�     h X     X�     ��P� ^�u����P���P�P      K              b t n - b u y . p n g c�     p Z     X�     n�P� ^�u����P�n�P��       �               B T N - B U ~ 1 . P N G       q�     ` P     X�     %��P� ^�u��%��P�%��P�      ~              f a v . i c o z�     ` P     X�     -��P� ^�u��-��P�-��P�       �              g o u . j p g {�     h V     X�     -��P� ^�u��D
�P�-��P��      �              
i c o n - 1 . p n g m }�     h V     X�     D
�P� ^�u��D
�P�D
�P��      �              
i c o n - 2 . p n g m ��     h V     X�     L1�P� ^�u��L1�P�L1�P��      �              
i c o n - 3 . p n g m ��     h V     X�     bX�P� ^�u��bX�P�bX�P��       �              
i c o n - 4 . p n g m ��     h V     X�     ��P� ^�u����P���P�                    
i c o n - 5 . p n g m ��     h V     X�     |��P� ���'�|��P�|��P�       �              
i c o n - 6 . p n g m ��     ` N     X�     |��P� ^�u�����P����P�(      $              n o . p n g B ��     h X     X�     ���P� ^�u�����P����P�`      `              s u b - p r o . p n g                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                

/** returns just extension of the provided filename (if any). */
std::string Path_GetExtension( const std::string & sPath )
{
	for ( std::string::const_reverse_iterator i = sPath.rbegin(); i != sPath.rend(); i++ )
	{
		if ( *i == '.' )
		{
			return std::string( i.base(), sPath.end() );
		}

		// if we find a slash there is no extension
		if ( *i == '\\' || *i == '/' )
			break;
	}

	// we didn't find an extension
	return "";
}

bool Path_IsAbsolute( const std::string & sPath )
{
	if( sPath.empty() )
		return false;

#if defined( WIN32 )
	if ( sPath.size() < 3 ) // must be c:\x or \\x at least
		return false;

	if ( sPath[1] == ':' ) // drive letter plus slash, but must test both slash cases
	{
		if ( sPath[2] == '\\' || sPath[2] == '/' )
			return true;
	}
	else if ( sPath[0] == '\\' && sPath[1] == '\\' ) // UNC path
		return true;
#else
	if( sPath[0] == '\\' || sPath[0] == '/' ) // any leading slash
		return true;
#endif

	return false;
}


/** Makes an absolute path from a relative path and a base path */
std::string Path_MakeAbsolute( const std::string & sRelativePath, const std::string & sBasePath )
{
	if( Path_IsAbsolute( sRelativePath ) )
		return Path_Compact( sRelativePath );
	else
	{
		if( !Path_IsAbsolute( sBasePath ) )
			return "";

		std::string sCompacted = Path_Compact( Path_Join( sBasePath, sRelativePath ) );
		if( Path_IsAbsolute( sCompacted ) )
			return sCompacted;
		else
			return "";
	}
}


/** Fixes the directory separators for the current platform */
std::string Path_FixSlashes( const std::string & sPath, char slash )
{
	if( slash == 0 )
		slash = Path_GetSlash();

	std::string sFixed = sPath;
	for( std::string::iterator i = sFixed.begin(); i != sFixed.end(); i++ )
	{
		if( *i == '/' || *i == '\\' )
			*i = slash;
	}

	return sFixed;
}


char Path_GetSlash()
{
#if defined(_WIN32)
	return '\\';
#else
	return '/';
#endif
}

/** Jams two paths together with the right kind of slash */
std::string Path_Join( const std::string & first, const std::string & second, char slash )
{
	if( slash == 0 )
		slash = Path_GetSlash();

	// only insert a slash if we don't already have one
	std::string::size_type nLen = first.length();
	if( !nLen )
		return second;
#if defined(_WIN32)
	if( first.back() == '\\' || first.back() == '/' )
	    nLen--;
#else
	char last_char = first[first.length()-1];
	if (last_char == '\\' || last_char == '/')
	    nLen--;
#endif

	return first.substr( 0, nLen ) + std::string( 1, slash ) + second;
}


std::string Path_Join( const std::string & first, const std::string & second, const std::string & third, char slash )
{
	return Path_Join( Path_Join( first, second, slash ), third, slash );
}

std::string Path_Join( const std::string & first, const std::string & second, const std::string & third, const std::string &fourth, char slash )
{
	return Path_Join( Path_Join( Path_Join( first, second, slash ), third, slash ), fourth, slash );
}

std::string Path_Join( 
	const std::string & first, 
	const std::string & second, 
	const std::string & third, 
	const std::string & fourth, 
	const std::string & fifth, 
	char slash )
{
	return Path_Join( Path_Join( Path_Join( Path_Join( first, second, slash ), third, slash ), fourth, slash ), fifth, slash );
}


std::string Path_RemoveTrailingSlash( const std::string & sRawPath, char slash )
{
	if ( slash == 0 )
		slash = Path_GetSlash();

	std::string sPath = sRawPath;
	std::string::size_type nCurrent = sRawPath.length();
	if ( nCurrent == 0 )
		return sPath;

	int nLastFound = -1;
	nCurrent--;
	while( nCurrent != 0 )
	{
		if ( sRawPath[ nCurrent ] == slash )
		{
			nLastFound = (int)nCurrent;
			nCurrent--;
		}
		else
		{
			break;
		}
	}
		
	if ( nLastFound >= 0 )
	{
		sPath.erase( nLastFound, std::string::npos );
	}
	
	return sPath;
}


/** Removes redundant <dir>/.. elements in the path. Returns an empty path if the 
* specified path has a broken number of directories for its number of ..s */
std::string Path_Compact( const std::string & sRawPath, char slash )
{
	if( slash == 0 )
		slash = Path_GetSlash();

	std::string sPath = Path_FixSlashes( sRawPath, slash );
	std::string sSlashString( 1, slash );

	// strip out all /./
	for( std::string::size_type i = 0; (i + 3) < sPath.length();  )
	{
		if( sPath[ i ] == slash && sPath[ i+1 ] == '.' && sPath[ i+2 ] == slash )
		{
			sPath.replace( i, 3, sSlashString );
		}
		else
		{
			++i;
		}
	}


	// get rid of trailing /. but leave the path separator
	if( sPath.length() > 2 )
	{
		std::string::size_type len = sPath.length();
		if( sPath[ len-1 ] == '.'  && sPath[ len-2 ] == slash )
		{
		  // sPath.pop_back();
		  sPath[len-1] = 0;  // for now, at least
		}
	}

	// get rid of leading ./ 
	if( sPath.length() > 2 )
	{
		if( sPath[ 0 ] == '.'  && sPath[ 1 ] == slash )
		{
			sPath.replace( 0, 2, "" );
		}
	}

	// each time we encounter .. back up until we've found the previous directory name
	// then get rid of both
	std::string::size_type i = 0;
	while( i < sPath.length() )
	{
		if( i > 0 && sPath.length() - i >= 2 
			&& sPath[i] == '.'
			&& sPath[i+1] == '.'
			&& ( i + 2 == sPath.length() || sPath[ i+2 ] == slash )
			&& sPath[ i-1 ] == slash )
		{
			// check if we've hit the start of the string and have a bogus path
			if( i == 1 )
				return "";
			
			// find the separator before i-1
			std::string::size_type iDirStart = i-2;
			while( iDirStart > 0 && sPath[ iDirStart - 1 ] != slash )
				--iDirStart;

			// remove everything from iDirStart to i+2
			sPath.replace( iDirStart, (i - iDirStart) + 3, "" );

			// start over
			i = 0;
		}
		else
		{
			++i;
		}
	}

	return sPath;
}


/** Returns true if these two paths are the same without respect for internal . or ..
* sequences, slash type, or case (on case-insensitive platforms). */
bool Path_IsSamePath( const std::string & sPath1, const std::string & sPath2 )
{
	std::string sCompact1 = Path_Compact( sPath1 );
	std::string sCompact2 = Path_Compact( sPath2 );
#if defined(WIN32)
	return !stricmp( sCompact1.c_str(), sCompact2.c_str() );
#else
	return !strcmp( sCompact1.c_str(), sCompact2.c_str() );
#endif
}


/** Returns the path to the current DLL or exe */
std::string Path_GetThisModulePath()
{
	// gets the path of vrclient.dll itself
#ifdef WIN32
	HMODULE hmodule = NULL;

	::GetModuleHandleEx( GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, reinterpret_cast<LPCTSTR>(Path_GetThisModulePath), &hmodule );

	wchar_t *pwchPath = new wchar_t[MAX_UNICODE_PATH];
	char *pchPath = new char[ MAX_UNICODE_PATH_IN_UTF8 ];
	::GetModuleFileNameW( hmodule, pwchPath, MAX_UNICODE_PATH );
	WideCharToMultiByte( CP_UTF8, 0, pwchPath, -1, pchPath, MAX_UNICODE_PATH_IN_UTF8, NULL, NULL );
	delete[] pwchPath;

	std::string sPath = pchPath;
	delete [] pchPath;
	return sPath;

#elif defined( OSX ) || defined( LINUX )
	// get the addr of a function in vrclient.so and then ask the dlopen system about it
	Dl_info info;
	dladdr( (void *)Path_GetThisModulePath, &info );
	return info.dli_fname;
#endif

}


/** returns true if the specified path exists and is a directory */
bool Path_IsDirectory( const std::string & sPath )
{
	std::string sFixedPath = Path_FixSlashes( sPath );
	if( sFixedPath.empty() )
		return false;
	char cLast = sFixedPath[ sFixedPath.length() - 1 ];
	if( cLast == '/' || cLast == '\\' )
		sFixedPath.erase( sFixedPath.end() - 1, sFixedPath.end() );

	// see if the specified path actually exists.

#if defined(POSIX)
	struct	stat	buf;
	if ( stat( sFixedPath.c_str(), &buf ) == -1 )
	{
		return false;
	}

#if defined( LINUX ) || defined( OSX )
	return S_ISDIR( buf.st_mode );
#else
	return (buf.st_mode & _S_IFDIR) != 0;
#endif

#else
	struct	_stat	buf;
	std::wstring wsFixedPath = UTF8to16( sFixedPath.c_str() );
	if ( _wstat( wsFixedPath.c_str(), &buf ) == -1 )
	{
		return false;
	}

	return (buf.st_mode & _S_IFDIR) != 0;
#endif
}

/** returns true if the specified path represents an app bundle */
bool Path_IsAppBundle( const std::string & sPath )
{
#if defined(OSX)
	@autoreleasepool {
		NSBundle *bundle = [ NSBundle bundleWithPath: [ NSString stringWithUTF8String:sPath.c_str() ] ];
		bool bisAppBundle = ( nullptr != bundle );
		return bisAppBundle;
	}
#else
	return false;
#endif
}

//-----------------------------------------------------------------------------
// Purpose: returns true if the the path exists
//-----------------------------------------------------------------------------
bool Path_Exists( const std::string & sPath )
{
	std::string sFixedPath = Path_FixSlashes( sPath );
	if( sFixedPath.empty() )
		return false;

#if defined( WIN32 )
	struct	_stat	buf;
	std::wstring wsFixedPath = UTF8to16( sFixedPath.c_str() );
	if ( _wstat( wsFixedPath.c_str(), &buf ) == -1 )
	{
		return false;
	}
#else
	struct stat buf;
	if ( stat ( sFixedPath.c_str(), &buf ) == -1)
	{
		return false;
	}
#endif

	return true;
}


//-----------------------------------------------------------------------------
// Purpose: helper to find a directory upstream from a given path
//-----------------------------------------------------------------------------
std::string Path_FindParentDirectoryRecursively( const std::string &strStartDirectory, const std::string &strDirectoryName )
{
	std::string strFoundPath = "";
	std::string strCurrentPath = Path_FixSlashes( strStartDirectory );
	if ( strCurrentPath.length() == 0 )
		return "";

	bool bExists = Path_Exists( strCurrentPath );
	std::string strCurrentDirectoryName = Path_StripDirectory( strCurrentPath );
	if ( bExists && stricmp( strCurrentDirectoryName.c_str(), strDirectoryName.c_str() ) == 0 )
		return strCurrentPath;

	while( bExists && strCurrentPath.length() != 0 )
	{
		strCurrentPath = Path_StripFilename( strCurrentPath );
		strCurrentDirectoryName = Path_StripDirectory( strCurrentPath );
		bExists = Path_Exists( strCurrentPath );
		if ( bExists && stricmp( strCurrentDirectoryName.c_str(), strDirectoryName.c_str() ) == 0 )
			return strCurrentPath;
	}

	return "";
}


//-----------------------------------------------------------------------------
// Purpose: helper to find a subdirectory upstream from a given path
//-----------------------------------------------------------------------------
std::string Path_FindParentSubDirectoryRecursively( const std::string &strStartDirectory, const std::string &strDirectoryName )
{
	std::string strFoundPath = "";
	std::string strCurrentPath = Path_FixSlashes( strStartDirectory );
	if ( strCurrentPath.length() == 0 )
		return "";

	bool bExists = Path_Exists( strCurrentPath );
	while( bExists && strCurrentPath.length() != 0 )
	{
		strCurrentPath = Path_StripFilename( strCurrentPath );
		bExists = Path_Exists( strCurrentPath );

		if( Path_Exists( Path_Join( strCurrentPath, strDirectoryName ) ) )
		{
			strFoundPath = Path_Join( strCurrentPath, strDirectoryName );
			break;
		}
	}
	return strFoundPath;
}


//-----------------------------------------------------------------------------
// Purpose: reading and writing files in the vortex directory
//-----------------------------------------------------------------------------
unsigned char * Path_ReadBinaryFile( const std::string &strFilename, int *pSize )
{
	FILE *f;
#if defined( POSIX )
	f = fopen( strFilename.c_str(), "rb" );
#else
	std::wstring wstrFilename = UTF8to16( strFilename.c_str() );
	// the open operation needs to be sharable, therefore use of _wfsopen instead of _wfopen_s
	f = _wfsopen( wstrFilename.c_str(), L"rb", _SH_DENYNO );
#endif
	
	unsigned char* buf = NULL;

	if ( f != NULL )
	{
		fseek(f, 0, SEEK_END);
		int size = ftell(f);
		fseek(f, 0, SEEK_SET);

		buf = new unsigned char[size];
		if (buf && fread(buf, size, 1, f) == 1)
		{
			if (pSize)
				*pSize = size;
		}
		else
		{
			delete[] buf;
			buf = 0;
		}

		fclose(f);
	}

	return buf;
}

uint32_t  Path_ReadBinaryFile( const std::string &strFilename, unsigned char *pBuffer, uint32_t unSize )
{
	FILE *f;
#if defined( POSIX )
	f = fopen( strFilename.c_str(), "rb" );
#else
	std::wstring wstrFilename = UTF8to16( strFilename.c_str() );
	errno_t err = _wfopen_s( &f, wstrFilename.c_str(), L"rb" );
	if ( err != 0 )
	{
		f = NULL;
	}
#endif

	uint32_t unSizeToReturn = 0;

	if ( f != NULL )
	{
		fseek( f, 0, SEEK_END );
		uint32_t size = (uint32_t)ftell( f );
		fseek( f, 0, SEEK_SET );

		if ( size > unSize || !pBuffer )
		{
			unSizeToReturn = (uint32_t)size;
		}
		else
		{
			if ( fread( pBuffer, size, 1, f ) == 1 )
			{
				unSizeToReturn = (uint32_t)size;
			}
		}

		fclose( f );
	}

	return unSizeToReturn;
}

bool Path_WriteBinaryFile(const std::string &strFilename, unsigned char *pData, unsigned nSize)
{
	FILE *f;
#if defined( POSIX )
	f = fopen(strFilename.c_str(), "wb");
#else
	std::wstring wstrFilename = UTF8to16( strFilename.c_str() );
	errno_t err = _wfopen_s( &f, wstrFilename.c_str(), L"wb" );
	if (err != 0)
	{
		f = NULL;
	}
#endif

	size_t written = 0;
	if (f != NULL) {
		written = fwrite(pData, sizeof(unsigned char), nSize, f);
		fclose(f);
	}

	return written == nSize ? true : false;
}

std::string Path_ReadTextFile( const std::string &strFilename )
{
	// doing it this way seems backwards, but I don't
	// see an easy way to do this with C/C++ style IO
	// that isn't worse...
	int size;
	unsigned char* buf = Path_ReadBinaryFile( strFilename, &size );
	if (!buf)
		return "";

	// convert CRLF -> LF
	size_t outsize = 1;
	for (int i=1; i < size; i++)
	{
		if (buf[i] == '\n' && buf[i-1] == '\r') // CRLF
			buf[outsize-1] = '\n'; // ->LF
		else
			buf[outsize++] = buf[i]; // just copy
	}

	std::string ret((char *)buf, outsize);
	delete[] buf;
	return ret;
}


bool Path_MakeWritable( const std::string &strFilename )
{
#if defined ( _WIN32 )
	std::wstring wstrFilename = UTF8to16( strFilename.c_str() );

	DWORD dwAttrs = GetFileAttributesW( wstrFilename.c_str() );
	if ( dwAttrs != INVALID_FILE_ATTRIBUTES && ( dwAttrs & FILE_ATTRIBUTE_READONLY ) )
	{
		return SetFileAttributesW( wstrFilename.c_str(), dwAttrs & ~FILE_ATTRIBUTE_READONLY );
	}
#else
	struct stat sb;

	if ( stat( strFilename.c_str(), &sb ) == 0 && !( sb.st_mode & S_IWUSR ) )
	{
		return ( chmod( strFilename.c_str(), sb.st_mode | S_IWUSR ) == 0 );
	}
#endif

	return true;
}

bool Path_WriteStringToTextFile( const std::string &strFilename, const char *pchData )
{
	FILE *f;
#if defined( POSIX )
	f = fopen( strFilename.c_str(), "w" );
#else
	std::wstring wstrFilename = UTF8to16( strFilename.c_str() );
	errno_t err = _wfopen_s( &f, wstrFilename.c_str(), L"w" );
	if ( err != 0 )
	{
		f = NULL;
	}
#endif
	
	bool ok = false;

	if ( f != NULL )
	{
		ok = fputs( pchData, f) >= 0;
		fclose(f);
	}

	return ok;
}

bool Path_WriteStringToTextFileAtomic( const std::string &strFilename, const char *pchData )
{
	std::string strTmpFilename = strFilename + ".tmp";

	if ( !Path_WriteStringToTextFile( strTmpFilename, pchData ) )
		return false;

	// Platform specific atomic file replacement
#if defined( _WIN32 )
	std::wstring wsFilename = UTF8to16( strFilename.c_str() );
	std::wstring wsTmpFilename = UTF8to16( strTmpFilename.c_str() );
	if ( !::ReplaceFileW( wsFilename.c_str(), wsTmpFilename.c_str(), nullptr, 0, 0, 0 ) )
	{
		// if we couldn't ReplaceFile, try a non-atomic write as a fallback
		if ( !Path_WriteStringToTextFile( strFilename, pchData ) )
			return false;
	}
#elif defined( POSIX )
	if ( rename( strTmpFilename.c_str(), strFilename.c_str() ) == -1 )
		return false;
#else
#error Do not know how to write atomic file
#endif

	return true;
}


#if defined(WIN32)
#define FILE_URL_PREFIX "file:///"
#else
#define FILE_URL_PREFIX "file://"
#endif

// ----------------------------------------------------------------------------------------------------------------------------
// Purpose: Turns a path to a file on disk into a URL (         h     (                 @                                      ?��/��S��5                                                    j��Xt��y��}��                                                ���}��s��f��9                                        �q=�p4�p- X���=�Ғ��                                    �l1�k
��k
��lv�k6�j��e��m[�n&                            �k
��k
��k
��m�o-�k
��k
��k
��k
��l\�k                    �k
��k
��k
��k;    �ko�k
��k
��k
��k
��k
��k
	                �k
��k
��k
��k
��k
z�kC�k
��k
��k
��k
��k
��k
��k
            �k
V�k
��k
��k
��k
��k
��k
X�k
G�k
��k
��k
��k
��k	D                �k
\�k
��k
��k
��k
��k
��l�l�k
��k
��k
��k
t                    �k,�k
��k
��k
��k
��l    �k
��k
��k
��k
;                        �m!�m#,�j��j��ne�k[�k
��k
��l9                                        Y���9�۽�t4�o+�p9                                        n�� w��u�����)                                                ���3���u��U��                                                    c��B��-��{��                ��  �  �  �  �  �  �  �  �  �  �!  �  �  �  �  �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      