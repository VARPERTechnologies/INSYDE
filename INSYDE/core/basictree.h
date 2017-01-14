#ifndef BASICTREE_H
#define BASICTREE_H

#include <QtWidgets>

#include "share_core_lib.h"
#include "undo.h"
#include "definitions.h"
#include "clipboard.h"

namespace core{

class CORE_LIB_IMPORT_EXPORT BasicTree : public QTreeView, public Clipboard
{
	public:

		/*!
		 * \brief BasicTree
		 * \param parent
		 */
		explicit BasicTree(QWidget *parent = 0);

		~BasicTree();

		void copyClick();
		void cutClick();
		void pasteClick();

	protected:

		void contextMenuEvent(QContextMenuEvent *event);
	private:
		Q_OBJECT

		void init();

};
}
#endif // BASICTREE_H
