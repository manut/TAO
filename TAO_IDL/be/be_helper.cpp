// $Id$

// ============================================================================
//
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_helper.cpp
//
// = DESCRIPTION
//   Provides helper classes to print generated code to the output
//
// = AUTHOR
//    Aniruddha Gokhale
//
//    Improvements by Carlos O'Ryan
//
// ============================================================================

#include "be_helper.h"
#include "be_codegen.h"
#include "idl_defines.h"
#include "ace/OS_NS_string.h"

ACE_RCSID (be,
           be_helper,
           "$Id$")

static const char copyright[] =
"// -*- C++ -*-\n"
"//\n"
"// $I" "d$\n\n"
"// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****\n"
"// TAO and the TAO IDL Compiler have been developed by:\n"
"//       Center for Distributed Object Computing\n"
"//       Washington University\n"
"//       St. Louis, MO\n"
"//       USA\n"
"//       http://www.cs.wustl.edu/~schmidt/doc-center.html\n"
"// and\n"
"//       Distributed Object Computing Laboratory\n"
"//       University of California at Irvine\n"
"//       Irvine, CA\n"
"//       USA\n"
"//       http://doc.ece.uci.edu/\n"
"// and\n"
"//       Institute for Software Integrated Systems\n"
"//       Vanderbilt University\n"
"//       Nashville, TN\n"
"//       USA\n"
"//       http://www.isis.vanderbilt.edu/\n"
"//\n"
"// Information about TAO is available at:\n"
"//     http://www.cs.wustl.edu/~schmidt/TAO.html";

TAO_NL::TAO_NL (void)
{
}

TAO_INDENT::TAO_INDENT (int do_now)
  :  do_now_ (do_now)
{
}

TAO_UNINDENT::TAO_UNINDENT (int do_now)
  :  do_now_ (do_now)
{
}

const TAO_NL be_nl;
const TAO_INDENT be_idt;
const TAO_INDENT be_idt_nl (1);
const TAO_UNINDENT be_uidt;
const TAO_UNINDENT be_uidt_nl (1);

// Methods of the TAO_OutStream class.

TAO_OutStream::TAO_OutStream (void)
  : fp_ (0),
    indent_level_ (0)
{
}

TAO_OutStream::~TAO_OutStream (void)
{
  // Close the underlying I/O handle only if it exists.
  if (this->fp_ != 0)
    {
      ACE_OS::fclose (this->fp_);
      this->fp_ = 0;
    }

  indent_level_ = 0;
}

int
TAO_OutStream::open (const char *fname,
                     TAO_OutStream::STREAM_TYPE st)
{
  if (fname != 0)
    {
      // File name exists, open an I/O file handle.
      this->fp_ = ACE_OS::fopen (fname, "w");

      if (this->fp_ != 0)
        {
          this->st_ = st;
          // Put the copyright notice.  Not for the gperf's temp input
          // file.
          if (st != TAO_OutStream::TAO_GPERF_INPUT)
            {
              ACE_OS::fprintf (this->fp_,
                               "%s\n",
                               copyright);

              ACE_OS::fflush (this->fp_);
            }

          return 0;
        }
      else
        {
          return -1;
        }
    }
  else
    {
      return -1;
    }
}

// Set and get the stream type.
void
TAO_OutStream::stream_type (TAO_OutStream::STREAM_TYPE st)
{
  this->st_ = st;
}

TAO_OutStream::STREAM_TYPE
TAO_OutStream::stream_type (void)
{
  return this->st_;
}

// Return the underlying lowlevel file pointer.
// indentation.
FILE *
TAO_OutStream::file (void)
{
  return this->fp_;
}

int
TAO_OutStream::incr_indent (unsigned short flag)
{
  indent_level_++;

  if (flag != 0)
    {
      return this->indent ();
    }
  else
    {
      // Do not indent output.
      return 0;
    }
}

// Indentation
int
TAO_OutStream::decr_indent (unsigned short flag)
{
  this->indent_level_--;
  // Just in case somebody gets "unindent happy".
  if (this->indent_level_ < 0)
    {
      // ACE_DEBUG ((LM_DEBUG, "negative indentation?\n"));
      this->indent_level_ = 0;
    }
  if (flag != 0)
    {
      return this->indent ();
    }
  else
    {
      // Do not indent output.
      return 0;
    }
}

int
TAO_OutStream::reset (void)
{
  this->indent_level_ = 0;
  return 0;
}

// Indented print.
int
TAO_OutStream::indent (void)
{
  // Based on the current indentation level, leave appropriate number of blank
  // spaces in the output.
  if (this->indent_level_ > 0)
    {
      for (int i = 0; i < this->indent_level_; i++)
        {
          ACE_OS::fprintf (this->fp_, "  ");
          ACE_OS::fflush (this->fp_);
        }
    }

  return 0;
}

int
TAO_OutStream::nl (void)
{
  ACE_OS::fprintf (this->fp_, "\n");
  this->indent ();
  return 0;
}

// Macro generation.
int
TAO_OutStream::gen_ifdef_macro (const char *flat_name,
                                const char *suffix,
                                bool add_stream_type_suffix)
{
  static char macro [NAMEBUFSIZE];

  ACE_OS::memset (macro,
                  '\0',
                  NAMEBUFSIZE);

  ACE_OS::sprintf (macro,
                   "_%s_",
                   tao_cg->upcase (flat_name));
  if (suffix != 0)
    {
      //ACE_OS::sprintf (macro, "%s_%s_", macro, cg->upcase (suffix));
      // Can't have macro on both sides of sprintf
      // I'm not sure if the first strcat of "_" should be here or
      // not, but having it gives the same functionality as the old
      // sprintf call...
      ACE_OS::strcat (macro, "_");
      ACE_OS::strcat (macro, tao_cg->upcase (suffix));
      ACE_OS::strcat (macro, "_");
    }

  // Append a suffix representing the stream type.
  if (add_stream_type_suffix)
    switch (this->st_)
    {
      case TAO_OutStream::TAO_CLI_HDR:
        ACE_OS::strcat (macro, "CH_");
        break;
      case TAO_OutStream::TAO_CLI_INL:
        ACE_OS::strcat (macro, "CI_");
        break;
      case TAO_OutStream::TAO_CLI_IMPL:
        ACE_OS::strcat (macro, "CS_");
        break;
      case TAO_OutStream::TAO_SVR_HDR:
        ACE_OS::strcat (macro, "SH_");
        break;
      case TAO_OutStream::TAO_IMPL_HDR:
        ACE_OS::strcat (macro, "IH_");
        break;
      case TAO_OutStream::TAO_IMPL_SKEL:
        ACE_OS::strcat (macro, "IS_");
        break;
      case TAO_OutStream::TAO_SVR_INL:
        ACE_OS::strcat (macro, "SI_");
        break;
      case TAO_OutStream::TAO_SVR_IMPL:
        ACE_OS::strcat (macro, "SS_");
        break;
      default:
        return -1;
    }

  *this << "\n\n#if !defined (" << macro << ")\n";
  *this << "#define " << macro;

  return 0;
}

int
TAO_OutStream::gen_endif (void)
{
  *this << "\n\n#endif /* end #if !defined */";

  return 0;
}

// Printf style variable argument print.
int
TAO_OutStream::print (const char *format, ...)
{
  int result = 0;
  va_list ap;
  va_start (ap, format);
  ACE_OSCALL (::vfprintf (this->fp_,
                          format,
                          ap),
              int,
              -1,
              result);

  ACE_OS::fflush (this->fp_);
  va_end (ap);

  return result;
}

TAO_OutStream &
TAO_OutStream::operator<< (const char *str)
{
  ACE_OS::fprintf (this->fp_, "%s", str);
  ACE_OS::fflush (this->fp_);
  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::UShort num)
{
  ACE_OS::fprintf (this->fp_,
                   "%hu",
                   num);

  ACE_OS::fflush (this->fp_);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::Short num)
{
  ACE_OS::fprintf (this->fp_,
                   "%hd",
                   num);

  ACE_OS::fflush (this->fp_);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::ULong num)
{
  ACE_OS::fprintf (this->fp_,
                   "%lu",
                   (unsigned long) num);

  ACE_OS::fflush (this->fp_);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::Long num)
{
  ACE_OS::fprintf (this->fp_,
                   "%ld",
                   (long) num);

  ACE_OS::fflush (this->fp_);

  return *this;
}

#if defined (ACE_WIN64)
TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::ULongLong num)
{
  ACE_OS::fprintf (this->fp_,
                   ACE_UINT64_FORMAT_SPECIFIER,
                   num);

  ACE_OS::fflush (this->fp_);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::LongLong num)
{
  ACE_OS::fprintf (this->fp_,
                   ACE_INT64_FORMAT_SPECIFIER,
                   num);

  ACE_OS::fflush (this->fp_);

  return *this;
}
#endif /* ACE_WIN64 */

TAO_OutStream &
TAO_OutStream::operator<< (const unsigned long num)
{
  ACE_OS::fprintf (this->fp_,
                   "%lu",
                   num);

  ACE_OS::fflush (this->fp_);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const long num)
{
  ACE_OS::fprintf (this->fp_,
                   "%ld",
                   num);

  ACE_OS::fflush (this->fp_);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const TAO_NL&)
{
  ACE_OS::fprintf (this->fp_ ,
                   "\n");
  this->indent ();

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const TAO_INDENT& i)
{
  this->incr_indent (0);

  if (i.do_now_)
    {
      this->nl ();
    }

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const TAO_UNINDENT& i)
{
  this->decr_indent (0);

  if (i.do_now_)
    {
      this->nl ();
    }

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (Identifier *id)
{
  return this->print (id);
}

TAO_OutStream &
TAO_OutStream::operator<< (UTL_IdList *id)
{
  return this->print (id);
}

TAO_OutStream &
TAO_OutStream::operator<< (AST_Expression *expr)
{
  return this->print (expr);
}
