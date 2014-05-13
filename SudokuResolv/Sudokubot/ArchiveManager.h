//
//  ArchiveManager.h
//  Sudokubot
//
//  Created by Haoest on 5/23/11.
//  Copyright 2011 none. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ArchiveEntry.h"

@interface ArchiveManager : NSObject {

}

-(id) initDefaultArchive;
-(ArchiveEntry*) getEntryById:(int) entryId;
-(int) addEntry:(ArchiveEntry*) entry;
-(void) updateEntry:(ArchiveEntry*) entry;
-(void) removeEntry:(int) entryId;
-(bool) saveArchive;
-(NSMutableArray*) getAllEntries;

@end
