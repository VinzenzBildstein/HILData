#include "TEaglePulser.h"

#include "TClass.h"
#include <cmath>
#include "TMath.h"

#include "TGRSIOptions.h"

TEaglePulser::TEaglePulser()
{
   Clear();
}

TEaglePulser::~TEaglePulser() = default;

TEaglePulser& TEaglePulser::operator=(const TEaglePulser& rhs)
{
   rhs.Copy(*this);
   return *this;
}

TEaglePulser::TEaglePulser(const TEaglePulser& rhs) : TDetector()
{
   rhs.Copy(*this);
}

void TEaglePulser::AddFragment(const std::shared_ptr<const TFragment>& frag, TChannel* chan)
{

   /// This function creates TEaglePulserHits for each fragment and stores them in separate front and back vectors
   if(frag == nullptr || chan == nullptr) {
      return;
   }

   auto hit = new TDetectorHit(*frag);
   Hits().push_back(hit);
}

void TEaglePulser::Print(Option_t*) const
{
   /// Prints out TEaglePulser information
   Print(std::cout);
}

void TEaglePulser::Print(std::ostream& out) const
{
   /// Prints TEaglePulser information to out
   std::ostringstream str;
   str << this << ": " << Hits().size() << " hits" << std::endl;
   for(const auto& hit : Hits()) {
      hit->Print(str);
   }
   str << "----------------------------------------" << std::endl;
   out << str.str();
}
