/*
 * Copyright (C) 2012 Hernan Badino <hernan.badino@gmail.com>
 *
 * This file is part of QCV
 *
 * QCV is under the terms of the GNU General Public License, version 2.
 * See the GNU General Public License, version 2 for details.
 * QCV is distributed "AS IS" without ANY WARRANTY, without even the
 * implied warranty of merchantability or fitness for a particular
 * purpose. 
 *
 * In no event shall the authors or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or
 * consequential damages arising in any way out of the use of this
 * software.
 *
 * By downloading, copying, installing or using the software you agree
 * to this license. Do not download, install, copy or use the
 * software, if you do not agree to this license.
 */

#ifndef __CLOCKTREEDLG_H
#define __CLOCKTREEDLG_H

/*@@@**************************************************************************
** \file  clockTreeWidget
* \author Hernan Badino
* \notes  
*******************************************************************************
*****             (C) Hernan Badino 2012 - All Rights Reserved            *****
******************************************************************************/

/* INCLUDES */
#include <QDialog>

/* CONSTANTS */

#include "clockTreeView.h"

/* PROTOTYPES */
class QGLWidget;
class QCheckBox;

namespace QCV
{

    /* PROTOTYPES */
    class CClockTreeItemModel;
    class CClockOpNode;

    /* CLASS DEFINITION */

    class CClockTreeDlg: public QDialog //, private Ui::CClockTreeDlgDesign
    {
        Q_OBJECT
        
    public:
        CClockTreeDlg ( QWidget *           f_parent_p,
                        CClockOpNode *    f_rootNode_p );

        ~CClockTreeDlg ();
        
    public slots:
        void updateTimes();
        void printTimes();

    protected:
        
        //void startDrag( Qt::DropActions supportedActions );

    private:
        
        /// Tree View
        CClockTreeView *                m_qtvClocks_p;

        /// Tree Model
        CClockTreeItemModel  *          m_treeItemModel_p;

        /// QCheck Box for updating times.
        QCheckBox *                     m_qcbUpdate_p;
    };
}


#endif // __CLOCKTREEDLG_H