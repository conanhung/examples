//
//  ArchiveTableViewController.m
//  Sudokubot
//
//  Created by Haoest on 4/12/11.
//  Copyright 2011 none. All rights reserved.
//

#import "ArchiveTableViewController.h"
#import "AppConfig.h"
#import "ArchiveEntry.h"
#import "BoardViewController.h"

@interface ArchiveTableViewController()

@property (nonatomic, retain) NSMutableArray* archiveContents;
@property (nonatomic, retain) ArchiveManager *archiveManager;

@end

@implementation ArchiveTableViewController

@synthesize archiveContents, archiveManager;
@synthesize rootViewDelegate;

- (void)dealloc
{
    [self.archiveContents removeAllObjects];
    self.archiveContents = nil;
    self.archiveManager = nil;
    [super dealloc];
    
}

-(void) viewDidUnload{
    
    [super viewDidUnload];
}

-(void) viewDidLoad{
    [super viewDidLoad];
}

+(ArchiveTableViewController*) archiveTableViewControllerFromDefaultArchive{
    ArchiveTableViewController* rv = [[ArchiveTableViewController alloc] initWithStyle:UITableViewStylePlain];
    [rv reloadDataSource];
    return [rv autorelease];
}

-(void) reloadDataSource{
    self.archiveManager = [[ArchiveManager alloc]initDefaultArchive];
    [self.archiveManager release];
    [self.archiveContents removeAllObjects];
    self.archiveContents = [self.archiveManager getAllEntries];
}

-(NSInteger) numberOfSectionsInTableView:(UITableView *)tableView{
    return 1;
}

-(NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    NSInteger rv = [self.archiveContents count]; // exclude last row
    return rv;
}

- (UITableViewCell*) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
	NSString *rowId = [NSString stringWithFormat:@"myRowId_%d", indexPath.row];
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:rowId];
	if (cell == nil) {
		cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:rowId] autorelease];
	}
    ArchiveEntry *archiveEntry = [self.archiveContents objectAtIndex:indexPath.row];
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:[AppConfig archiveDateFormat]];
	NSString *label = [NSString stringWithFormat:@"%@ : %@", [dateFormatter stringFromDate:[archiveEntry getCreationDateGMT]], archiveEntry.comments ];
    [dateFormatter release];
	cell.textLabel.text = label;
    UIFont* font = cell.textLabel.font;
    cell.textLabel.font = [font fontWithSize:[AppConfig archiveCellFontHeight]];  
	return cell;
}

-(CGFloat) tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return [AppConfig archiveCellHeight];
}

-(void) tableView: (UITableView*) tableView didSelectRowAtIndexPath:(NSIndexPath*) indexPath{
    NSArray *archive = self.archiveContents;
    NSInteger index = indexPath.row;
    ArchiveEntry* entry = [archive objectAtIndex:index];
    [tableView deselectRowAtIndexPath:indexPath animated:true];
    [self.rootViewDelegate showBoardViewWithEntry:entry];
}

-(void) tableView:(UITableView*) tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath{
    if (editingStyle == UITableViewCellEditingStyleDelete){
        ArchiveEntry *entry = [archiveContents objectAtIndex:indexPath.row];
        [self.archiveManager removeEntry:entry.entryId];
        [archiveContents removeObjectAtIndex:indexPath.row]; 
        NSArray *deletions = [NSArray arrayWithObjects:indexPath, nil];
        [self.tableView deleteRowsAtIndexPaths:deletions withRowAnimation:YES];
    }
}

-(void) saveArchive{
    [self.archiveManager saveArchive];
}

@end
