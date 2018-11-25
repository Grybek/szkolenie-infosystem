// ---------------------------------------------------------------------------

#ifndef user_infoH
#define user_infoH
// ---------------------------------------------------------------------------
#include <System.hpp>
#include <vector>
// ---------------------------------------------------------------------------

namespace klienci {

	class UserInfo {
	public:

		enum UserStatus {
			ustActive = 'A', // operator czynny
			ustBlocked = 'B', // operator zablokowany (kilka pr�b nieudanego zalogowania)
			ustSuspended = 'U', // operator zwieszony (dzia�anie administratora)
			ustErased = 'Z', // operator wykre�lony
			ustUndefined = '?'
		};

		// Rodzaj czynno�ci do wykonania
		enum UserAction {
			uacView, // tylko podgl�d
			uacEdit, // edycja i podgl�d
			uacErase, // usuwanie i podgl�d
			uacAdd, // dodawanie
			uacBrowse, // przegl�danie
			uacPayment // zaksi�gowanie wp�aty
		};

		// Oznaczenie systemu
		enum System {
			sysBO, // baza osobowa
			sysPD // podatki od nieruchomo�ci
		};

		static UserStatus stringToUserStatus(const String& status);

		typedef std::vector<String> UserRights;

		int Ident;
		String Name;
		String Password;
		String Forename;
		String Surname;
		UserStatus Status;
		UserRights Rights;

		UserInfo();

		bool isDefined() const ;
		bool checkRight(const String& right) const ;
		bool checkRight(UserAction action, System system = sysBO) const ;
	};
}

#endif
