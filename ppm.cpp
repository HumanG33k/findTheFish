#include "ppm.hpp"
#include <string.h>

using namespace std;

PPMBitmap::PPMBitmap( const int width, const int height ) 
	: m_ptr( NULL ), m_width( width ), m_height ( height )
{
	m_ptr = new uchar[m_width * m_height * 3];
	memset( m_ptr, 0, m_width * m_height * sizeof(uchar) * 3 );
}

PPMBitmap::PPMBitmap( const char *const name ) 
	: m_ptr( NULL ), m_width( 0 ), m_height ( 0 )
{
	ifstream file( name, ios::in | ios::binary );
	if ( !file ) {
		cerr << "Cannot open PPM file " << name << endl;
		exit( EXIT_FAILURE );
	}
	string MagicNumber, line;
	
	// MagicNumber
	getLine( file, line );
	istringstream iss1( line );
	iss1 >> MagicNumber;
	if ( MagicNumber != "P6" ) { // Binary ? or nothing ?
		cerr << "Error reading PPM file " << name << ": unknown Magic Number \"" << MagicNumber 
			 << "\". Only P6 is supported" << endl << endl;
		exit( EXIT_FAILURE );
	}

	// Image size
	getLine( file, line );
	istringstream iss2( line );
	iss2 >> m_width >> m_height;
	if ( m_width <= 0 || m_height <= 0 ) {
		cerr << "Wrong image size " << m_width << " x " << m_height << endl;
		exit( EXIT_FAILURE );
	}

	// Max channel value
	int maxChannelVal;
	getLine( file, line );
	istringstream iss3( line );
	iss3 >> maxChannelVal;
	if ( maxChannelVal > 255 ) {
		cerr << "Max channel value too high in " << name << endl;
		exit( EXIT_FAILURE );
	}

	// Allocate pixels
	m_ptr = new uchar[m_height * m_width * 3];

	// Read pixels
	for ( int y = m_height; y-- > 0; ) { // Reading each line
		file.read( reinterpret_cast<char *>( m_ptr + y * m_width * 3), m_width * 3 );
	}
}

void PPMBitmap::getLine( ifstream &file, string &s ) {
	for (;;) {
		if (!getline( file, s ) ) {
			cerr << "Error reading PPM file" << endl;
			exit( EXIT_FAILURE );
		}
		string::size_type index = s.find_first_not_of( "\n\r\t " );
		if ( index != string::npos && s[index] != '#' )
			break;
	}
}

void PPMBitmap::saveTo( const char *name ) const {
	ofstream file( name, ios::out | ios::trunc | ios::binary );
	
	file << "P6" << endl;						// Magic Number !
	file << m_width << " " << m_height << endl;	// Image size
	file << "255" << endl;						// Max R G B

	for ( int y = m_height; y > 0; --y ) { // Writing each line
		file.write( (const char *)( m_ptr + y * m_width * 3 * sizeof(uchar)), m_width * 3 ); 
	}
	file.close();
}




