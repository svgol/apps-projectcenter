/*
   GNUstep ProjectCenter - http://www.gnustep.org/experience/ProjectCenter.html

   Copyright (C) 2001-2004 Free Software Foundation

   Authors: Philippe C.D. Robert
            Serg Stoyan
	    
   Description: This is the project type 'Application' for GNUstep. You never 
                should create it yourself but use PCAppProj for doing this. 
		Otherwise needed files don't get copied to the right place.

   This file is part of GNUstep.

   This application is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This application is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA.
*/

#ifndef _PCAppProject_h_
#define _PCAppProject_h_

#include <AppKit/AppKit.h>
#include <ProjectCenter/PCDefines.h>
#include <ProjectCenter/PCProject.h>
#include <ProjectCenter/PCProjectInspector.h>

#include <Protocols/ProjectType.h>

@interface PCAppTextField : NSTextField
{
}

@end

@interface PCAppProject : PCProject <ProjectType>
{
  IBOutlet NSBox          *projectAttributesView;
  IBOutlet NSPopUpButton  *appTypeField;
  IBOutlet NSTextField    *appClassField;

  PCAppTextField          *activeTextField;
  IBOutlet PCAppTextField *appImageField;
  IBOutlet PCAppTextField *helpFileField;
  IBOutlet PCAppTextField *mainNIBField;

  IBOutlet NSImageView    *iconView;
  NSImage                 *icon;
  IBOutlet NSButton       *setFieldButton;
  IBOutlet NSButton       *clearFieldButton;

  IBOutlet NSButton       *docTypesButton;

  IBOutlet NSPanel        *docTypesPanel;
  IBOutlet NSButton       *addDocTypeButton;
  IBOutlet NSButton       *removeDocTypeButton;
  IBOutlet NSButton       *docBasedAppButton;
  IBOutlet NSScrollView   *docTypesScroll;

  NSTableView             *docTypesList;
  NSTableColumn           *typeColumn;       // NSName
  NSTableColumn           *nameColumn;       // NSHumanReadableName
  NSTableColumn           *extensionsColumn; // NSUnixExtensions
  NSTableColumn           *iconColumn;       // NSIcon
  NSTableColumn           *roleColumn;       // NSRole
  NSTableColumn           *classColumn;      // NSDocumentClass
  NSMutableArray          *docTypesItems;

  IBOutlet NSTextField    *docTypeLabel;
  IBOutlet NSTextField    *docTypeField;
  IBOutlet NSTextField    *docNameLabel;
  IBOutlet NSTextField    *docNameField;
  IBOutlet NSTextField    *docIconLabel;
  IBOutlet NSTextField    *docIconField;
  IBOutlet NSTextField    *docExtensionsLabel;
  IBOutlet NSTextField    *docExtensionsField;
  IBOutlet NSTextField    *docRoleLabel;
  IBOutlet NSTextField    *docRoleField;
  IBOutlet NSTextField    *docClassLabel;
  IBOutlet NSTextField    *docClassField;

  NSMutableDictionary     *infoDict;
}

// ----------------------------------------------------------------------------
// --- Init and free
// ----------------------------------------------------------------------------

- (id)init;
- (void)loadInfoFile;
- (void)dealloc;

- (PCProject *)createProjectAt:(NSString *)path;

@end

@interface PCAppProject (GeneratedFiles)

- (void)writeInfoEntry:(NSString *)name forKey:(NSString *)key;
- (BOOL)writeInfoFile;
- (BOOL)writeMakefile;
- (void)appendHead:(PCMakefileFactory *)mff;
- (void)appendTail:(PCMakefileFactory *)mff;

@end

#endif