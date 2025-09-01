/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_SUPPLIER_H
#define _VDSUITE_USER_PAF_WIDGET_W_SUPPLIER_H

#include <paf/widget/factory.h>
#include <paf/widget/w_plane.h>

SCE_PAF_IMPORTED_FROM_PRX extern paf::ui::FactoryFuncTable g_factorySupplier;

namespace paf {

	namespace ui {

		class Supplier : public Plane
		{
		public:

			static const char *TypeName(void);

			virtual ~Supplier();

			virtual bool IsInherit(char const *) const;
			virtual char *GetTypeName(void) const;

		protected:
			unsigned char m_unk_0x280[0x28];

			SCE_PAF_IMPORTED_FROM_PRX static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_SUPPLIER_H */