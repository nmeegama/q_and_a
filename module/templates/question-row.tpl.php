<?php
/**
 * @file
 * the tpl file to return a row of questions
 *
 */
?>
<div class="col-xs-12 pull-left" style="border-bottom: 1px solid #ccc; margin: 5px 0;padding-bottom: 5px;">
    <div class="col-xs-2 alert-info">
      <?php print $row['votes'] ?>
    </div>
  <div class="col-xs-2 alert-success">
    <?php print $row['answers'] ?>
  </div>
  <div class="col-xs-2 alert-danger">
    <?php print $row['views'] ?>
  </div>
  <div class="col-xs-6 alert-link">
    <?php print $row['question_title'] ?>
  </div>
</div>